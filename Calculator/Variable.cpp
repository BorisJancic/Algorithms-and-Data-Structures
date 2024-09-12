#include "Variable.hpp"
#include <iostream>

Variable::Variable(std::string variable_name, double variable_value) {
    name = variable_name;
    value = variable_value;
    next = nullptr;
}
Variable::~Variable() {}

std::string Variable::get_name() { return name; }
double Variable::get_value() { return value; }
Variable *Variable::get_next() { return next; }

void Variable::set_name(std::string new_name) {
    name = new_name;
}
void Variable::set_value(double new_value) {
    value = new_value;
}
void Variable::set_next(Variable* new_next) {
    next = new_next;
}
