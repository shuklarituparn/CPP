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
sp1.swap(sp2);


    // Example 3
    // Example 4
    // Example 6
}