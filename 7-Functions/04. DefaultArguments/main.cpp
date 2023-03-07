// Section 11
// Default Arguments
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double calc_cost(double base_cost = 100.0, double tax_rate = 0.06, double shipping = 3.50); //function that returns the double value and has default value

void greeting(string name,  string prefix = "Mr.", string suffix = ""); //doesn't return anything but has a default value of the string

double calc_cost(double base_cost, double tax_rate, double shipping) {  //in the actual function we don't have the default values. we had it in prototype
    return base_cost += (base_cost * tax_rate) + shipping;
}

void greeting(string name,  string prefix, string suffix) {  //in the actual function we don't have the default values of the string
    cout << "Hello " << prefix + " " + name + " " + suffix << endl;
}


int main() {
    double cost{ 0 };
    cost = calc_cost(100.0, 0.08, 4.25);        // will use no defaults  100 + 8 + 4-Statement and Operators.25
    
    cout << fixed << setprecision(2);
    cout << "Cost is: " << cost << endl;    // 112.25
    
    cost = calc_cost(100.0, 0.08);                  // will use default shipping  100 + 8 + 3.50 
    cout << "Cost is: " << cost << endl;    // 111.50

    cost = calc_cost(200.0);                         // will use default tax and shipping   200 + 12 + 3.50
    cout << "Cost is: " << cost << endl;    // 215.50
    
    cost = calc_cost();
    cout << "Cost is: " << cost << endl;    // 100 + 6 + 3.50
    
    greeting("Glenn Jones", "Dr.", "M.D.");
    greeting("James Rogers", "Professor", "Ph.D.");
    greeting("Frank Miller", "Dr.");
    greeting("William Smith");   //as it's not passed with extra parameters the default one will be used the one in the function prototype
    greeting("Mary Howard", "Mrs.", "Ph.D.");

    cout << endl;
    return 0;
}
