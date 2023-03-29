/*
ig we create a pointer and then try to reuse it without deleting we'll get a memory leak as the old data that the pointer is pointing to gets lost





*/

class Queue{
    public:

        void PushFront(int value);
        void PopBack();
        int Top();
        int Size();
        void clear(); //to clear the data, delete all the data
        void Resize(int new_capacity);

        
}