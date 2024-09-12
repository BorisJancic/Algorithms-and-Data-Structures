#include <iostream>
#include "Graph.hpp"
#include "illegal_exception.hpp"

int main() {
    std::string command = "";
    Graph* G = new Graph;
    
    while (command != "END") {
        try {
            std::cin >> command;
            if (command == "LOAD") {
                std::string filename;
                std::cin >> filename;
                G->load(filename);
            } else if (command == "INSERT") {
                unsigned a = 0;
                unsigned b = 0;
                unsigned w = 0;
                std::cin >> a >> b >> w;
                G->insert(a, b, w);
            } else if (command == "PRINT") {
                unsigned a = 0;
                std::cin >> a;
                G->print(a);
            } else if (command == "DELETE") {
                unsigned v = 0;
                std::cin >> v;
                G->delete_vertex(v);
            } else if (command == "MST") {
                G->MST();
            } else if (command == "COST") {
                G->cost();
            }
            
        } catch (illegal_exception &ex) {
            std::cout << "illegal argument" << std::endl;
        }
    }


    delete G;
    return 0;
}