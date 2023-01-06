#include "calculator.h"

double Calculator::Calculate(double x, char oper, double y) {
    /* The switch statement is similar to an "if" statement, whereas
    the item within parentheses is the statement being checked. The
    switch statement checks to see which one of the cases the 
    paramenter matches. If it doesn't match any of the cases then
    it will default to the default case below, in this case it is
    return 0.0*/
    switch (oper) {
        case '+':
            return x + y; 
        case '-':
            return x - y; 
        case '*': 
            return x * y;
        case '/': 
            return x / y; 
        default:
            return 0.0;
    }
}