#include<iostream>

int main()
{
unsigned long long int b {0};
   uint64_t a {0};
   std::cin>>a;
   while (a!=0)                                 `
{
    b=b*10+a%10;
    a=a/10;


}
std::cout<< b;
    
	return 0;
}