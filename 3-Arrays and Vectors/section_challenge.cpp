#include <iostream>
#include <vector>

int main(){

    std::vector <int> vector1 {};
    vector1.push_back(10);
    vector1.push_back(20);
    std::cout<<"Vector 1: "<<std::endl;
    std::cout<<"\n"<<std::endl;
    std::cout<<vector1.at(0)<<"\n"<<std::endl;
    std::cout<<vector1.at(1)<<"\n"<<std::endl;
    std::cout<<" The Vector 1 has"<<vector1.size()<<"Elements"<<std::endl;

    std::vector <int> vector2 {};
    vector2.push_back(100);
    vector2.push_back(200);
    std::cout<<"Vector 2: "<<std::endl;
    std::cout<<"\n"<<std::endl;
    std::cout<<vector2.at(0)<<"\n"<<std::endl;
    std::cout<<vector2.at(1)<<"\n"<<std::endl;
    std::cout<<" The Vector 2 has"<<vector2.size()<<"Elements"<<std::endl;

    std::vector <std::vector<int>> vector_2d;
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    
    std::cout<<"The 2D Vector is: "<<std::endl;
    std::cout<<vector_2d.at(0).at(0)<<"\t"<<vector_2d.at(0).at(1)<<"\n"<<std::endl;
    std::cout<<vector_2d.at(1).at(0)<<"\t"<<vector_2d.at(1).at(1)<<"\n"<<std::endl;

    vector1.at(0)=1000;

    std::cout<<vector_2d.at(0).at(0)<<"\t"<<vector_2d.at(0).at(1)<<"\n"<<std::endl; //output doesn't change
    std::cout<<vector_2d.at(1).at(0)<<"\t"<<vector_2d.at(1).at(1)<<"\n"<<std::endl;

    //output doesn't change as when we're adding element to a vector, we're making a copy of element

    std::cout<<"Vector 1: "<<std::endl;
    std::cout<<"\n"<<std::endl;
    std::cout<<vector1.at(0)<<"\n"<<std::endl; //Now we can see that the Vector 1 is changed
    std::cout<<vector1.at(1)<<"\n"<<std::endl;


    return 0;
}