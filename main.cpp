/* Name: Calculator App using C++
 * Note: This is my first personal project!
 * 
 * Author: Nathan Nguyen
 * Last updated: 01-05-2023
 */

#include <iostream> 
#include "calculator.h"

using namespace std; 

int main() {

    double x = 0.0;
    double y = 0.0; 
    double result = 0.0; 
    char oper = '+'; 

    cout << "Calculator Console App " << endl << endl; 
    cout << "Please enter the operation to perform (+, - , *, /): "; 
    cin >> oper; 

    return 0; 
}