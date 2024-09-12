#include "OpenAddressing.hpp"
#include "HashTable.hpp"
#include <iostream>

// Check if address is 0

OpenAddressing::OpenAddressing(unsigned N, unsigned P): HashTable(N, P) {
    table = new OpenProcess*[N/P] { nullptr };
}
OpenAddressing::~OpenAddressing() {
    for (unsigned i = 0; i < table_size; i++) {
        if (table[i] != nullptr) {
            delete table[i];
        }
    }
    delete[] table;
}

void OpenAddressing::Insert(unsigned PID) {
    if (PID == 0) {
        std::cout << "failure" << std::endl;
        return;
    }
    if (current_size >= table_size) {
        std::cout << "failure" << std::endl;
        return;
    }
    bool slot_found = false;
    unsigned slot = 0;

    for (unsigned i = 0; i < table_size; i++) {
        unsigned h = hash(PID, i);
        if (table[h] == nullptr && slot_found == false) {
            table[h] = new OpenProcess(PID, i);
            current_size++;
            std::cout << "success" << std::endl;
            return;
        }
        if (table[h] == nullptr && slot_found == true) {
            break;
        }
        if (table[h]->get_PID() == PID) {
            std::cout << "failure" << std::endl;
            return;
        }
        if (table[h]->get_PID() == 0 && slot_found == false) {
            slot_found = true;
            slot = h;
        }
    }
    if (slot_found == true) {
        table[slot]->set_PID(PID);
        current_size++;
        std::cout << "success" << std::endl;
        return;
    }
    std::cout << "failure" << std::endl;
}
void OpenAddressing::Search(unsigned PID) {
    if (PID == 0) {
        std::cout << "not found" << std::endl;
        return;
    }
    for (unsigned i = 0; i < table_size; i++) {
        unsigned h = hash(PID, i);
        if (table[h] == nullptr) {
            std::cout << "not found" << std::endl;
            return;
        }
        if (table[h]->get_PID() == PID) {
            std::cout << "found " << PID << " in " << h << std::endl;
            //std::cout << "return PID" << std::endl;
            return;
        }
    }
    std::cout << "not found" << std::endl;
}
void OpenAddressing::Write(unsigned PID, unsigned ADDR, int x) {
    if (PID == 0 || ADDR >= page_size) {
        std::cout << "failure" << std::endl;
        return;
    }
    for (unsigned i = 0; i < table_size; i++) {
        unsigned h = hash(PID, i);
        if (table[h] == nullptr) {
            std::cout << "failure" << std::endl;
            return;
        }
        if (table[h]->get_PID() == PID) {
            memory[h*page_size + ADDR] = x;
            std::cout << "success" << std::endl;
            return;
        }
    }
    std::cout << "failure" << std::endl;
}
void OpenAddressing::Read(unsigned PID, unsigned ADDR) {
    if (PID == 0 || ADDR >= page_size) {
        std::cout << "failure" << std::endl;
        return;
    }
    for (unsigned i = 0; i < table_size; i++) {
        unsigned h = hash(PID, i);
        if (table[h] == nullptr) {
            std::cout << memory[h*page_size+1] << "failure" << std::endl;
            return;
        }
        if (table[h]->get_PID() == PID) {
            std::cout << ADDR << " " << memory[h*page_size + ADDR] << std::endl;
            return;
        }
    }
    std::cout << "failure" << std::endl;
}
void OpenAddressing::Delete(unsigned PID) {
    if (PID == 0) {
        std::cout << "failure" << std::endl;
        return;
    }
    for (unsigned i = 0; i < table_size; i++) {
        unsigned h = hash(PID, i);
        if (table[h] == nullptr) {
            std::cout << "failure" << std::endl;
            return;
        }
        if (table[h]->get_PID() == PID) {
            table[h]->set_PID(0);
            current_size--;
            std::cout << "success" << std::endl;
            return;
        }
    }
    std::cout << "failure" << std::endl;
}
void OpenAddressing::Print(unsigned m) {}
