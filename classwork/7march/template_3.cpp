template<bool b, typename T1, typename T2>
struct conditional {
 typedef T1 type;
};


template<typename T1, typename T2>
struct conditional<false, T1, T2> {
 typedef T2 type;
};


conditional::type // T1 if b is true, T2 if b is false

