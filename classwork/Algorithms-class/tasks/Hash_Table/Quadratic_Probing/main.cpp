#include <iostream>
#define SIZE 10

using namespace std;
 
template <class T>
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
 
int Hash(int key){ //hash function that returns a hash  value
    return key % SIZE;
}
 
int QuadraticProbe(int HashTable[], int key){ //quadratic probing function that finds a spot in the hash table and returns its index
    int index = Hash(key);
    int i = 0;
    while (HashTable[(index+i*i) % SIZE] != 0){ //here we see that the loop is moved forward by taking a square of the loop variable
        i++;
    }
    return (index + i*i) % SIZE;  //returning the index of the spot that we found
}
 
void Insert(int HashTable[], int key){  // Insert function that inserts a key into the hash table
    int index = Hash(key); //
 
    if (HashTable[index] != 0){  //checking if the location is already occupied
        index = QuadraticProbe(HashTable, key); //if it is then, we find a spot in the hash table
    }
    HashTable[index] = key;  //then we go to the spot and place the key
}
 
int Search(int HashTable[], int key){
    int index = Hash(key); //getting the index of the key
    int i = 0;
    while (HashTable[(index+i*i) % SIZE] != key){  //we loop till we find the key   
        i++;
        if (HashTable[(index + i*i) % SIZE] == 0){ //if we find that there's an empty spot in the hash table then we break out
            return -1;
        }
    }
    return (index + i*i) % SIZE;  //if the key is found then we return the index of the key
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