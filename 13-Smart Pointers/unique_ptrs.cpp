//Don't try to compile. It's just theory


void UseRawPointer()
{
    // Using a raw pointer -- not recommended.
    Song* pSong = new Song(L"Nothing on You", L"Bruno Mars");    //we create raw pointers using the keyword new 

    // Use pSong...

    // Don't forget to delete!
    delete pSong;      //we have to delete the raw pointers after using it or we'll have a memory leak
}


void UseSmartPointer()   //smart pointers are declared in the memory library in c++
{
    // Declare a smart pointer on stack and pass it the raw pointer.
    unique_ptr<Song> song2(new Song(L"Nothing on You", L"Bruno Mars"));  //declaring the unique pointer of type Song and of the name song2 and passing the raw pointer using the keyword new into our unique pointer

    // Use song2...
    wstring s = song2->duration_;   //using the smart pointer and 
    //...

} // song2 is deleted automatically here.   //at the end of the scope it automatically get's deleted



/* A unique_ptr does not share its pointer. It cannot be copied to another unique_ptr, passed by value to a function, or used in any C++ Standard Library algorithm that requires copies to be made. A unique_ptr can only be moved. This means that the ownership of the memory resource is transferred to another unique_ptr and the original unique_ptr no longer owns it. We recommend that you restrict an object to one owner, because multiple ownership adds complexity to the program logic. Therefore, when you need a smart pointer for a plain C++ object, use unique_ptr, and when you construct a unique_ptr, use the make_unique helper function.

The following diagram illustrates the transfer of ownership between two unique_ptr instances. */

unique_ptr<Song> SongFactory(const std::wstring& artist, const std::wstring& title) /* Wide string- wstring
String class for wide characters.

This is an instantiation of the basic_string class template that uses wchar_t as the character type, with its default char_traits and allocator types (see basic_string for more info on the template). */
{
    // Implicit move operation into the variable that stores the result.
    return make_unique<Song>(artist, title);
}

void MakeSongs()
{
    // Create a new unique_ptr with a new object.
    auto song = make_unique<Song>(L"Mr. Children", L"Namonaki Uta");

    // Use the unique_ptr.
    vector<wstring> titles = { song->title }; 

    // Move raw pointer from one unique_ptr to another.
    unique_ptr<Song> song2 = std::move(song);  //we can move unique pointers but we cannot copy them 

    // Obtain unique_ptr from function that returns by value.
    auto song3 = SongFactory(L"Michael Jackson", L"Beat It"); 
}

////////////////////////////////////////////////////////////////////////////////

//create unique pointer instances and use them with vector

void SongVector()
{
    vector<unique_ptr<Song>> songs;
    
    // Create a few new unique_ptr<Song> instances
    // and add them to vector using implicit move semantics.
    songs.push_back(make_unique<Song>(L"B'z", L"Juice")); 
    songs.push_back(make_unique<Song>(L"Namie Amuro", L"Funky Town")); 
    songs.push_back(make_unique<Song>(L"Kome Kome Club", L"Kimi ga Iru Dake de")); 
    songs.push_back(make_unique<Song>(L"Ayumi Hamasaki", L"Poker Face"));

    // Pass by const reference when possible to avoid copying.
    for (const auto& song : songs)
    {
        wcout << L"Artist: " << song->artist << L"   Title: " << song->title << endl; 
    }    
}

////////////////////////////////////////////////////////////////////////////////

//Initialize unique pointer that is a class member

class MyClass
{
private:
    // MyClass owns the unique_ptr.
    unique_ptr<ClassFactory> factory;
public:

    // Initialize by using make_unique with ClassFactory default constructor.
    MyClass() : factory (make_unique<ClassFactory>())
    {
    }

    void MakeClass()
    {
        factory->DoSomething();
    }
};

////////////////////////////////////////////////////////////////////////////////

//Make uniue pointer to an array:

// Create a unique_ptr to an array of 5 integers.
auto p = make_unique<int[]>(5);

// Initialize the array.
for (int i = 0; i < 5; ++i)
{
    p[i] = i;
    wcout << p[i] << endl;
}