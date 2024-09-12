#include "Calculator.hpp"
#include <iostream>

Calculator::Calculator() {
    n = 0;
    max = 0;
    head = nullptr;
}
Calculator::~Calculator() {
    Variable* current_node = head;
    while (current_node != nullptr) {
        Variable* temp = current_node;
        current_node = current_node->get_next();
        delete temp;
    }
}

void Calculator::start() {
    std::string command="";
    while (command != "END") {
        std::cin >> command;
        if (command == "CRT") { 
            int n;
            std::cin >> n;
            set_max(n);
        }
        else if (command == "DEF") {
            std::string name;
            double value;
            std::cin >> name  >> value;
            append_variable(name, value);
        }
        else if (command == "ADD") {
            std::string x, y, z;

            std::cin >> x >> y >> z;
            add(x, y, z);
        }
        else if (command == "SUB") {
            std::string x;
            std::string y;
            std::string z;

            std::cin >> x >> y >> z;
            subtract(x, y, z);
        }
        else if (command == "REM") {
            std::string x;
            std::cin >> x;
            delete_variable(x);
        }
        else if (command == "PRT") {
            std::string x;
            std::cin >> x;
            print_value(x);
        }
        else if (command == "END") {
            break;
        }
        else { std::cout << "Invalid Command" << std::endl; }

    }
}

void Calculator::append_variable(std::string &variable_name, double variable_value) {
    if (n >= max) {
        std::cout << "failure" << " Max Exceeded" << std::endl;
        return;
    }

    Variable *tmp = new Variable(variable_name, variable_value);
    Variable *current_node = head;

    if (head == nullptr) {
        head = tmp;
        n = 1;
        std::cout << "success" << std::endl;
        return;
    }
    while (current_node != nullptr) {
        if (current_node->get_name() == variable_name) {
            std::cout << "failure" << " Variable Exists" << std::endl;
            delete tmp;
            return;
        }
        if (current_node->get_next() == nullptr) {
            current_node->set_next(tmp);
            n += 1;
            std::cout << "success" << std::endl;
            return;
        }
        current_node = current_node->get_next();
    }
}

void Calculator::delete_variable(std::string &variable_name) {
    if (head == nullptr) {
        std::cout << "failure" << " NULL" << std::endl;
        return;
    }

    Variable *current_node = head;

    if (current_node->get_name() == variable_name) {
        head = head->get_next();
        delete current_node;
        std::cout << "success" << std::endl;
        n -= 1;
        return;
    }
    while (current_node->get_next() != nullptr) {
        if (current_node->get_next()->get_name() == variable_name) {
            Variable *tmp = current_node->get_next();
            current_node->set_next(current_node->get_next()->get_next());
            delete tmp;
            n -= 1;
            std::cout << "success" << std::endl;
            return;
        }
        current_node = current_node->get_next();
    }

    std::cout << "failure" << "Variable Not Found" << std::endl;
}

void Calculator::print_value(std::string &variable_name) {
    Variable *current_node = head;
    
    while (current_node != nullptr) {
        if (current_node->get_name() == variable_name) {
            std::cout << current_node->get_value() << std::endl;
            std::cout << "success" << std::endl;
            return;
        }
        current_node = current_node->get_next();
    }
    std::cout << "variable " + variable_name + " not found" << std::endl;
}

void Calculator::add(std::string &x, std::string &y, std::string &z) {
    Variable *current_node = head;
    Variable *x_node = nullptr;
    Variable *y_node = nullptr;
    Variable *z_node = nullptr;

    while (current_node != nullptr) {
        if (current_node->get_name() == x)
            x_node = current_node;
        if (current_node->get_name() == y)
            y_node = current_node;
        if (current_node->get_name() == z)
            z_node = current_node;
        current_node = current_node->get_next();
    }
    if ( (x_node != nullptr) && (y_node != nullptr) && (z_node != nullptr) ) {
        z_node->set_value(x_node->get_value() + y_node->get_value());
        std::cout << "success " << x_node->get_value() << y_node->get_value() << std::endl;
    }
    else {
        std::cout << "failure" << std::endl;
    }
}
void Calculator::subtract(std::string &x, std::string &y, std::string &z) {
    Variable *current_node = head;
    Variable *x_node = nullptr;
    Variable *y_node = nullptr;
    Variable *z_node = nullptr;

    while (current_node != nullptr) {
        if (current_node->get_name() == x)
            x_node = current_node;
        if (current_node->get_name() == y)
            y_node = current_node;
        if (current_node->get_name() == z)
            z_node = current_node;
        current_node = current_node->get_next();
    }
    if ( (x_node != nullptr) && (y_node != nullptr) && (z_node != nullptr) ) {
        z_node->set_value(x_node->get_value() - y_node->get_value());
        std::cout << "success " << x_node->get_value() << y_node->get_value() << std::endl;
    }
    else {
        std::cout << "failure" << std::endl;
    }
}

void Calculator::set_max(int new_max) {
    max = new_max;
    std::cout << "success" << " " << get_max() << std::endl;

}
void Calculator::set_n(int new_n) { n = new_n; }
void Calculator::set_head(Variable *new_head) { head = new_head; }

int Calculator::get_max() { return max; }
int Calculator::get_n() { return n; }
Variable* Calculator::get_head() { return head; }
