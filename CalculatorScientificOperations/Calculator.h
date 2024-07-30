//
// Created by maciejl on 7/23/24.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include "DividingByZero.h"
#include <cmath>
#include <stdexcept>
#include <stack>
#include <sstream>
#include <cctype>
#include <map>

class Calculator {


public:
    //methods

    //basic arithmetic
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

    int modulo(int a, int b);

    //trygonometry
    double sin(double angle);
    double cos(double angle);
    double tan(double angle);


    //logarithms
    double log(double value, double base);
    double log10(double value);

    //A method for evaluating infix expressions
    double evaluateInfix(const std::string& expression);

    int precedence(char op);

    double applyOp(double a, double b, char op) {
        switch (op) {
            case '+': return add(a, b);
            case '-': return subtract(a, b);
            case '*': return multiply(a, b);
            case '/': return divide(a, b);
            default: throw std::invalid_argument("Unknown operator");
        }
    }
};



#endif //CALCULATOR_H
