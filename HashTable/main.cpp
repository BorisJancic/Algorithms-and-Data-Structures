#include <iostream>
#include "HashTable.hpp"
#include "Chaining.hpp"
#include "OpenAddressing.hpp"


int main() {
    HashTable* table = nullptr;

    std::string type = "";
    std::string command = "";
    std::cin >> type;

    while (command != "END") {
        std::cin >> command;
        if (command == "M") {
            unsigned N, P;
            std::cin >> N >> P;
            if (type == "OPEN") {
                table = new OpenAddressing(N, P);
            } else {
                table = new Chaining(N, P);
            }
        } else if (command == "INSERT") {
            unsigned PID;
            std::cin >> PID;
            table->Insert(PID);
        } else if (command == "SEARCH") {
            unsigned PID;
            std::cin >> PID;
            table->Search(PID);
        } else if (command == "WRITE") {
            unsigned PID, ADDR;
            int x;
            std::cin >> PID >> ADDR >> x;
            table->Write(PID, ADDR, x);
        } else if (command == "READ") {
            unsigned PID, ADDR;
            std::cin >> PID >> ADDR;
            table->Read(PID, ADDR);
        } else if (command == "DELETE") {
            unsigned PID;
            std::cin >> PID;
            table->Delete(PID);
        } else if (command == "PRINT") {
            unsigned m;
            std::cin >> m;
            table->Print(m);
        }
    }

    delete table;

    return 0;
}
