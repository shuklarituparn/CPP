#include<iostream>

void reverse( uint64_t a){
uint64_t b {0};
while (a!=0)
{
    b=b*10+a%10;
    a=a/10;


}
std::cout<< b;
    
}
int main()
{
   uint64_t a {0};
   std::cin>>a;
   reverse(a);
	return 0;
}