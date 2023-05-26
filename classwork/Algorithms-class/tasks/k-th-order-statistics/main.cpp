//
// Created by rituparn on 26.05.23.
//
#include <iostream>
#include <vector>

std::vector<long long int> series(int number_of_terms, int first_term, int second_term){
    std::vector<long long int> sequence;
    sequence.resize(number_of_terms);
    sequence.at(0)=first_term;
    sequence.at(1)=second_term;
    for (int i = 2; i <number_of_terms ; ++i) {
        sequence[i]= ((sequence.at(i-1)*123)+sequence.at(i-2)*45)%(10004321);
    }
    return sequence;
}

int main() {
    int n;
    std::cout << "Enter the number of terms in the series: ";
    std::cin >> n;

    long long a0, a1;
    std::cout << "Enter the initial values A0 and A1: ";
    std::cin >> a0 >> a1;

    std::vector<long long> series2;
    series2.resize(n);
    series2=series(n,a0,a1);

    std::cout << "Generated Series: ";
    for (int i = 0; i < n; i++) {
        std::cout << series2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

