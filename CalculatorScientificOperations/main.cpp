#include <iostream>

#include "Calculator.h"

int main() {
    Calculator calc;

        std::string expression;
        std::cout << "Enter an expression: ";
        std::getline(std::cin, expression);
        double result = calc.evaluateInfix(expression);
        std::cout << "Result: " << result << std::endl;


    return 0;
}