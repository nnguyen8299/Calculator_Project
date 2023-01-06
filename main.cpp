/* Name: Calculator App using C++
 * Note: This is my first personal project!
 * 
 * Author: Nathan Nguyen
 * Last updated: 01-05-2023
 */

#include <iostream> 
#include <string>
#include "calculator.h"

using namespace std; 

int main() {

    Calculator c; 

    double x = 0.0;
    double y = 0.0; 
    double result = 0.0; 
    char oper = '+'; 

    cout << "Calculator Console App " << endl << endl; 
    cout << "Please enter the operation to perform (+, - , *, /): "; 
    cin >> oper; 
    cout << "Enter first number: "; 
    cin >> x; 
    cout << "Enter second number: ";
    cin >> y; 
    cout << "Calculating..."; 
    double answer = c.Calculate(x, oper, y); 
    cout << "Your answer is: " << answer << endl; 
    cout << "Thank you for demo-ing this Calculator"; 

    return 0; 
}
