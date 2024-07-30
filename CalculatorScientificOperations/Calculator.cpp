//
// Created by maciejl on 7/23/24.
//

#include "Calculator.h"

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {

    return a * b;
}

double Calculator::divide(double a, double b) {

    if(b == 0) {
        throw DividingByZero();
    }

    return a/b;
}

int Calculator::modulo(int a, int b) {

    if(b == 0) {
        throw std::invalid_argument("Modulo by zero\n");
    }
    return a % b;

}

double Calculator::sin(double angle) {
    return std::sin(angle);
}

double Calculator::cos(double angle) {
    return std::cos(angle);
}

double Calculator::tan(double angle) {
    return std::tan(angle);
}

double Calculator::log(double value, double base) {

    if(value <= 0) {
        throw std::invalid_argument("Logarithm of non-positive value");
    }
    if(base <= 0 || base == 1) {
        throw std::invalid_argument("Invalid logarithm base");
    }

    return std::log(value) / std::log(base);

}

double Calculator::log10(double value) {

    if (value <= 0) {
        throw std::invalid_argument("Logarithm of non-positive value");
    }
    return std::log10(value);
}

double Calculator::evaluateInfix(const std::string& expression) {
    std::stack<double> values;
    std::stack<char> ops;
    std::istringstream tokens(expression);
    char token;

    while (tokens >> token) {

        if (token == ' ') continue;


        if (isdigit(token) || token == '.') {
            tokens.putback(token);
            double value;
            tokens >> value;
            values.push(value);
        }

        else if (token == '(') {
            ops.push(token);
        }

        else if (token == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.pop(); //remove left bracket
        }

        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(token)) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(token);
        }
    }
    while (!ops.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int Calculator::precedence(char op) {
    if(op == '+' || op == '-') {
        return 1;
    }
    if(op == '*' || op == '/') {
        return 2;
    }

    return 0;
}