#include "Calculator.hpp"
#include <iostream>


int main() {
    Calculator* calculator = new Calculator;
    calculator->start();
    delete calculator;

    return 0;
}