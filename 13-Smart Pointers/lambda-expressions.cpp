/* In C++ 11 and later, the lambda expression are used to create anonymous fucntions that are pased into some function without the need to declare them. */

#include <algorithm>
#include <cmath>

void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
        // Lambda expression begins
        [](float a, float b) {
            return (std::abs(a) < std::abs(b));
        } // end of lambda expression
    );
}

/*
Syntax of the lambda expression

[capture_list] (arguments) -> return_type { function_body }

The capture list the variable from the scope the lambda expression has the access to.

The argument list is a list of arguments to the lambda expression.

The return type is the type of the return value that the lambda expression returns.

*/


/*
Lamda expression also has the following syntax:

[=] () mutable throw ()-> type { return_type }

[]= capture clause specifies the variable that the lambda expression can capture

Variables that have & are passed by reference, those which don't have & are passed by value.

[]= signifies that the lambda expression doesn't access any variable in the scope.

[&] means that all the variables that are referred are captured by reference.

[=] means that all the variables that are referred are captured by value.

[=, *this] works. this is captured by value.
[&, n] n is passed by reference.
*/


/*
USE OF MUTABLE IN LAMBDA EXPRESSIONS: (to modify variables that are passed)

Typically, a lambda's function call operator is const-by-value, but use of the mutable keyword cancels this out. It doesn't produce mutable data members. The mutable specification enables the body of a lambda expression to modify variables that are captured by value.

*/


