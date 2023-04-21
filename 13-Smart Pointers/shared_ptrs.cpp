/* The shared_ptr type is a smart pointer in the C++ standard library that is designed for scenarios in which more than one owner might have to manage the lifetime of the object in memory. After you initialize a shared_ptr you can copy it, pass it by value in function arguments, and assign it to other shared_ptr instances. All the instances point to the same object, and share access to one "control block" that increments and decrements the reference count whenever a new shared_ptr is added, goes out of scope, or is reset. When the reference count reaches zero, the control block deletes the memory resource and itself. */

// shared_ptr-examples.cpp
// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct MediaAsset 
{
    virtual ~MediaAsset() = default; // make it polymorphic.  By adding default keyword we make sure to not delete the original struct
};

struct Song : public MediaAsset   //struct song that is derived from the public of the MediaAsset 
{
    std::wstring artist;  //it has fields of widestring artist
    std::wstring title;  //it also has field of wstring title
    Song(const std::wstring& artist_, const std::wstring& title_) :  //constructor
        artist{ artist_ }, title{ title_ } {}
};

struct Photo : public MediaAsset   //struct photo that is derived from the public of the MediaAsset
{
    std::wstring date;  //field date
    std::wstring location; //field location
    std::wstring subject;  //field subject
    Photo(
        const std::wstring& date_, //photo enum that contains many value
        const std::wstring& location_,
        const std::wstring& subject_) :
        date{ date_ }, location{ location_ }, subject{ subject_ } {}
};

using namespace std;

int main()
{
    // The examples go here, in order:
   // Use make_shared function when possible.
auto sp1 = make_shared<Song>(L"The Beatles", L"Im  Happy Just to Dance With You"); //the auto keyword automatically decides the variable type and we use make_shared to create a shared ptr

// Ok, but slightly less efficient. 
// Note: Using new expression as constructor argument
// creates no named variable for other code to access.
shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance")); //shared pointer of the type struct called Song 

// When initialization must be separate from declaration, e.g. class members, 
// initialize with nullptr to make your programming intent explicit.
shared_ptr<Song> sp5(nullptr); //when making a new shared_ptr we intilize it as nullptr in order to not have any confusion

//Equivalent to: shared_ptr<Song> sp5;
//...
sp5 = make_shared<Song>(L"Elton John", L"I'm Still Standing");  //assigning the vlaues



    // Example 2



//Initialize with copy constructor. Increments ref count.
auto sp3 (sp2);                //sp3 is shared ptr having the vlaue sp2            

//Initialize via assignment. Increments ref count.
auto sp4 = sp2;  //usign the assignment operator but same 

//Initialize with nullptr. sp7 is empty.
shared_ptr<Song> sp7(nullptr);

// Initialize with another shared_ptr. sp1 and sp2
// swap pointers as well as ref counts.
sp1.swap(sp2);//we can swap the pointers. as we are swapping the pointers. We swapping the second pointer sp2 with s1


    // Example 3
/* 
shared_ptr is also helpful in C++ Standard Library containers when you're using algorithms that copy elements. You can wrap elements in a shared_ptr, and then copy it into other containers with the understanding that the underlying memory is valid as long as you need it, and no longer. The following example shows how to use the remove_copy_if algorithm on shared_ptr instances in a vector.
 */




vector<shared_ptr<Song>> v {
  make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"),
  make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"),
  make_shared<Song>(L"Thalía", L"Entre El Mar y Una Estrella")
};  //making a container of the shared_ptrs and then initializing it with different values


/* C++ has two built-in types for characters, char, which is used with std::string, and wchar_t, which is used with std::wstring. If you write a string literal in regular quotes, C++ treats it as an string made of chars, which can be used with std::string. To tell C++ that you're trying to make a string literal made of wchar_ts - which is what you'll need to use to work with std::wstring, you need to prefix it with an L because that's just how C++ is defined. */

vector<shared_ptr<Song>> v2;
remove_copy_if(v.begin(), v.end(), back_inserter(v2), [] (shared_ptr<Song> s) 
{
    return s->artist.compare(L"Bob Dylan") == 0;
});


/* This line of code invokes the remove_copy_if() algorithm, which takes four arguments:

    v.begin() and v.end(): the range of elements in the input vector v that we want to filter and copy.
    back_inserter(v2): an iterator that points to the end of the output vector v2, indicating where the copied elements should be inserted.
    [] (shared_ptr<Song> s) { return s->artist.compare(L"Bob Dylan") == 0; }: a lambda function that takes a shared_ptr<Song> object s and returns a bool. The lambda function is used to determine whether a given element in the input range should be filtered out or not. In this case, the lambda function checks whether the artist name of the current Song object pointed to by s is equal to "Bob Dylan", and returns true if it is.

The remove_copy_if() algorithm copies all elements from the input range that do not satisfy the condition specified by the lambda function, and inserts them into v2 using the back_inserter iterator. Therefore, v2 will contain all Song objects from v that have an artist name different from "Bob Dylan". */



for (const auto& s : v2)
{
    wcout << s->artist << L":" << s->title << endl;
}  //in this example we are printing the artists that we have for the shared pts





    // Example 4


/* You can use dynamic_pointer_cast, static_pointer_cast, and const_pointer_cast to cast a shared_ptr. These functions resemble the dynamic_cast, static_cast, and const_cast operators. The following example shows how to test the derived type of each element in a vector of shared_ptr of base classes, and then copy the elements and display information about them.
 */


vector<shared_ptr<MediaAsset>> assets { //making a vector of the shared pointer of the type Media assets named assets
  make_shared<Song>(L"Himesh Reshammiya", L"Tera Surroor"),//first pointer to object that stores the values
  make_shared<Song>(L"Penaz Masani", L"Tu Dil De De"),
  make_shared<Photo>(L"2011-04-06", L"Redmond, WA", L"Soccer field at Microsoft.")
};

vector<shared_ptr<MediaAsset>> photos;

copy_if(assets.begin(), assets.end(), back_inserter(photos), [] (shared_ptr<MediaAsset> p) -> bool
{
    // Use dynamic_pointer_cast to test whether
    // element is a shared_ptr<Photo>.
    shared_ptr<Photo> temp = dynamic_pointer_cast<Photo>(p);
    return temp.get() != nullptr;
});

for (const auto&  p : photos)
{
    // We know that the photos vector contains only 
    // shared_ptr<Photo> objects, so use static_cast.
    wcout << "Photo location: " << (static_pointer_cast<Photo>(p))->location << endl;
}



    // Example 6


/* The following example shows how shared_ptr overloads various comparison operators to enable pointer comparisons on the memory that is owned by the shared_ptr instances. */



    // Initialize two separate raw pointers.
// Note that they contain the same values.
auto song1 = new Song(L"Village People", L"YMCA");
auto song2 = new Song(L"Village People", L"YMCA");

// Create two unrelated shared_ptrs.
shared_ptr<Song> p1(song1);    
shared_ptr<Song> p2(song2);

// Unrelated shared_ptrs are never equal.
wcout << "p1 < p2 = " << std::boolalpha << (p1 < p2) << endl;
wcout << "p1 == p2 = " << std::boolalpha <<(p1 == p2) << endl;

// Related shared_ptr instances are always equal.
shared_ptr<Song> p3(p2);
wcout << "p3 == p2 = " << std::boolalpha << (p3 == p2) << endl;

}