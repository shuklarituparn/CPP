#include <iostream>
#define SIZE 10

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;  //using flush to print output on a new line 
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int Hash(int key){
    return key % SIZE;  //hash function returning the hash value
}
 
int LinearProbe(int HashTable[], int key){
    int index = Hash(key);
    int i = 0;
    while (HashTable[(index+i) % SIZE] != 0){ //going on the table to find the empty spot 
        i++;
    }
    return (index + i) % SIZE;  //returning the index of the empty spot found on the hash table
}
 
void Insert(int HashTable[], int key){  //inserting the key in the hash table
    int index = Hash(key);
 
    if (HashTable[index] != 0){  //if the position is not empty and we are having a collision
        index = LinearProbe(HashTable, key); //we find the next position that's empty using probing 
    }
    HashTable[index] = key;  //storing the key in the position
}
 
int Search(int HashTable[], int key){  //passing the hash table and the key to search
    int index = Hash(key);
    int i = 0;
    while (HashTable[(index+i) % SIZE] != key){ //looping through the hash table to find the key using linear increments
        i++;
        if (HashTable[(index + i) % SIZE] == 0){ //we break out as soon as we get one empty spot
            return -1;
        }
    }
    return (index + i) % SIZE; //otherwise we return the index of the key
}
 
 
int main() {
 
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, " A");
 
    // Hash Table
    int HashTable[10] = {0};
    for (int i=0; i<n; i++){
        Insert(HashTable, A[i]);
    }
    Print(HashTable, SIZE, "HT");
 
    int index = Search(HashTable, 25);
    cout << "key found at: " << index << endl;
 
    index = Search(HashTable, 35);
    cout << "key found at: " << index << endl;
 
    return 0;
}