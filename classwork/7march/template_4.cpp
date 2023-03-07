
template <typename T>
struct S {
    template <int M, int N>
    struct A{}; }

template <>
struct S<int> {
   static const int A = 0;
}

template <typename T>
void f() {
    typename S<T>::template A<1,2> a;
}
