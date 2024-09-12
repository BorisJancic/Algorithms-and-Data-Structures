#include "Variable.hpp"

#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
    public:
        Calculator();
        ~Calculator();
        void start();
    private:
        int max;
        int n;
        Variable *head;

        void append_variable(std::string &variable_name, double variable_value);
        void delete_variable(std::string &variable_name);
        void print_value(std::string &variable_name);

        void add(std::string &x, std::string &y, std::string &z);
        void subtract(std::string &x, std::string &y, std::string &z);

        void set_max(int new_max);
        void set_n(int new_n);
        void set_head(Variable *new_head);

        int get_max();
        int get_n();
        Variable* get_head();
};

#endif // CALCULATOR_H