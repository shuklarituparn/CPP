#include <iostream>
#define SIZE 10
#define PRIME 7

using namespace std;
 
template <class T> //class and typename are same here
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int Hash(int key){  //hash function
    return key % SIZE;
}
 
int PrimeHash(int key){  //second hash function
    return PRIME - (key % PRIME);
}
 
int DoubleHash(int HashTable[], int key){  //function that returns spot to put the key
    int index = Hash(key);
    int i = 0;
    while (HashTable[(Hash(index) + i * PrimeHash(index)) % SIZE] != 0){
        i++;
    }
    return (index + i * PrimeHash(index)) % SIZE; //returning the spot
}
 
void Insert(int HashTable[], int key){ //Insert function that inserts the key into the hash table
    int index = Hash(key); //finding the spot to put the key
 
    if (HashTable[index] != 0){  //if the spot is not empty then find the spot using double hashingq
        index = DoubleHash(HashTable, key);
    }
    HashTable[index] = key; //putting the key in the spot
}
 
int Search(int HashTable[], int key){ //The search function that searches for the key in the table
    int index = Hash(key);
    int i = 0;
    while (HashTable[(Hash(index) + i * PrimeHash(index)) % SIZE] != key){
        i++;
        if (HashTable[(Hash(index) + i * PrimeHash(index)) % SIZE] == 0){
            return -1;
        }
    }
    return (Hash(index) + i * PrimeHash(index)) % SIZE;
}
 
 
int main() {
 
    int A[] = {5, 25, 15, 35, 95};
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