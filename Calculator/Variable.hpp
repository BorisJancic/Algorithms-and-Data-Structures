#include <iostream>

#ifndef VARIABLE_H
#define VARIABLE_H

class Variable {
    public:
        Variable(std::string variable_name, double variable_value);
        ~Variable();

        std::string get_name();
        double get_value();
        Variable *get_next();

        void set_name(std::string new_name);
        void set_value(double new_value);
        void set_next(Variable* new_next);
        
    private:
        std::string name;
        double value;
        Variable* next;
};

#endif // VARIABLE_H