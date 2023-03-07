/*

Create a template class that compares two integers and tells which is bigger

*/

#include <iostream>

template <typename  T>// T is a type of variable which class will contain
class S{
    public:
    T a_;
    T b_;
    S(T a, T b): a_(a), b_(b){};
    T Max(){
        if(a_>b_){
            return a_;
        }
        else{return b_;}
    };
};

int main()
{
	S<std::string> s("bc", "ade");
    std::cout<<s.Max();

	return 0;
}

