//
// Created by rituparn on 01.03.23.
//
 /*
  * Capacity

    size() – Returns the number of elements in the vector.

    max_size() – Returns the maximum number of elements that the vector can hold.

    capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of
    elements.

    resize(n) – Resizes the container so that it contains ‘n’ elements.

    empty() – Returns whether the container is empty.

    shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the
    capacity.

    reserve() – Requests that the vector capacity be at least enough to contain n elements.
  */

// C++ program to illustrate the
// capacity function in vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    cout << "Size : " << g1.size();
    cout << "\nCapacity : " << g1.capacity();
    cout << "\nMax_Size : " << g1.max_size();

    // resizes the vector size to 4-Statement and Operators
    g1.resize(4);

    // prints the vector size after resize()
    cout << "\nSize : " << g1.size();

    // checks if the vector is empty or not
    if (g1.empty() == false)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";

    // Shrinks the vector
    g1.shrink_to_fit();
    cout << "\nVector elements are: ";
    for (auto it = g1.begin(); it != g1.end(); it++)
        cout << *it << " ";

    return 0;
}
