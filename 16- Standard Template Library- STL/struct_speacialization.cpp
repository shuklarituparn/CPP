//struct_speacialization

/* Struct specialization is used to provide a different implementation of a template struct or class for a specific type or set of types.

There are situations where the default implementation of a template struct or class may not be suitable for certain types. In such cases, we can use struct specialization to provide a different implementation of the template struct or class for those specific types.

For example, consider the following template class that provides a generic implementation for finding the maximum value in an array: */
template <typename T>
class MaxFinder {
public:
  T findMax(T* arr, int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
      if (arr[i] > max) {
        max = arr[i];
      }
    }
    return max;
  }
};

/* This implementation works fine for most types, but if we want to use it for a custom type that does not support the comparison operators > and <, then the implementation will not work. In such a case, we can use struct specialization to provide a different implementation of the template class for that specific type.

Here's an example of how struct specialization can be used to provide a different implementation of MaxFinder for a custom type that does not support comparison operators:
 */

 struct MyType {
  int value;
  // no comparison operators defined
};

// specialization of MaxFinder for MyType
template<>
class MaxFinder<MyType> {
public:
  MyType findMax(MyType* arr, int size) {
    MyType max = arr[0];
    for (int i = 1; i < size; ++i) {
      if (arr[i].value > max.value) { // access value member directly
        max = arr[i];
      }
    }
    return max;
  }
};

/* In this example, we define a custom type MyType that does not have comparison operators defined. We then provide a specialization of MaxFinder for MyType that accesses the value member directly to compare objects instead of using comparison operators.

This way, we can provide a different implementation of a template struct or class for specific types that require special treatment, while still maintaining the generic implementation for other types. */