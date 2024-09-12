#include "Chaining.hpp"
#include <iostream>

Chaining::Chaining(unsigned N, unsigned P): HashTable(N, P) {
    table = new ChainProcess*[N/P] { nullptr };
    memory_free = new bool[N/P];
    for (unsigned i = 0; i < table_size; i++) {
        memory_free[i] = true;
    }
}
Chaining::~Chaining() {
    for (unsigned i = 0; i < table_size; i++) {
        ChainProcess* current_node = table[i];
        while (current_node != nullptr) {
            ChainProcess* tmp = current_node;
            current_node = current_node->get_next();
            delete tmp;
        }
    }
    delete[] table;
    delete[] memory_free;
}

void Chaining::Insert(unsigned PID) {
    if (PID == 0 || current_size >= table_size) {
        std::cout << "failure" << std::endl;
        return;
    }

    unsigned h = hash(PID, 0);
    unsigned memory_address;
    if (memory_free[h] == true) {
        memory_address = h;
        memory_free[h] = false;
    } else {
        for (unsigned i = 0; i < table_size; i++) {
            if (memory_free[i] == true) {
                memory_address = i;
                memory_free[i] = false;
                break;
            }
        }
    }

    if (table[h] == nullptr) {
        table[h] = new ChainProcess(PID, memory_address);
        current_size++;
        std::cout << "success" << std::endl;
        return;
    }
    ChainProcess* current_node = table[h];
    if (PID > current_node->get_PID()) {
        table[h] = new ChainProcess(PID, memory_address, current_node);
        current_size++;
        std::cout << "success" << std::endl;
        return;
    }

    while (current_node != nullptr) {
        if (current_node->get_PID() > PID) {
            if (current_node->get_next() == nullptr) {
                current_node->set_next(new ChainProcess(PID, memory_address));
                current_size++;
                std::cout << "success" << std::endl;
                return;
            }
            if (PID > current_node->get_next()->get_PID()) {
                current_node->set_next(new ChainProcess(PID, memory_address, current_node->get_next()));
                current_size++;
                std::cout << "success" << std::endl;
                return;
            }
        }
        current_node = current_node->get_next();
    }
    std::cout << "failure" << std::endl;
}
void Chaining::Search(unsigned PID) {
    if (PID == 0) {
        std::cout << "failure" << std::endl;
        return;
    }
    unsigned h = hash(PID, 0);
    ChainProcess* current_node = table[h];
    if (current_node == nullptr) {
        std::cout << "not found" << std::endl;
        return;
    }
    while (current_node != nullptr) {
        if (current_node->get_PID() == PID) {
            std::cout << "found " << PID << " in " << h << std::endl;
            return;
        }
        current_node = current_node->get_next();
    }
    std::cout << "not found" << std::endl;
}
void Chaining::Write(unsigned PID, unsigned ADDR, int x) {
    if (PID == 0 || ADDR >= page_size) {
        std::cout << "failure" << std::endl;
        return;
    }
    unsigned h = hash(PID, 0);
    ChainProcess* current_node = table[h];
    while (current_node != nullptr) {
        if (current_node->get_PID() == PID) {
            memory[(current_node->get_address()*page_size) + ADDR] = x;
            std::cout << "success" << std::endl;
            return;
        }
        current_node = current_node->get_next();
    }
    std::cout << "failure" << std::endl;
}
void Chaining::Read(unsigned PID, unsigned ADDR) {
    if (PID == 0 || ADDR >= page_size) {
        std::cout << "failure" << std::endl;
        return;
    }
    unsigned h = hash(PID, 0);
    ChainProcess* current_node = table[h];
    while (current_node != nullptr) {
        if (current_node->get_PID() == PID) {
            std::cout << ADDR << " " << memory[(current_node->get_address()*page_size) + ADDR] << std::endl;
            return;
        }
        current_node = current_node->get_next();
    }
    std::cout << "failure" << std::endl;
}
void Chaining::Delete(unsigned PID) {
    if (PID == 0) {
        std::cout << "failure" << std::endl;
        return;
    }
    unsigned h = hash(PID, 0);
    ChainProcess* current_node = table[h];
    if (current_node == nullptr) {
        std::cout << "failure" << std::endl;
        return;
    }
    if (current_node->get_PID() == PID) {
        table[h] = current_node->get_next();
        memory_free[current_node->get_address()] = true;
        delete current_node;
        current_size--;
        std::cout << "success" << std::endl;
        return;
    }
    while (current_node->get_next() != nullptr) {
        if (current_node->get_next()->get_PID() == PID) {
            ChainProcess* tmp = current_node->get_next();
            current_node->set_next(current_node->get_next()->get_next());
            memory_free[current_node->get_address()] = true;
            delete tmp;
            current_size--;
            std::cout << "success" << std::endl;
            return;
        }
        current_node = current_node->get_next();
    }
    std::cout << "failure" << std::endl;
}
void Chaining::Print(unsigned m) {
    ChainProcess* current_node = table[m];
    if (current_node == nullptr) {
        std::cout << "chain is empty" << std::endl;
        return;
    }
    while (current_node != nullptr) {
        std::cout << current_node->get_PID() << " ";
        current_node = current_node->get_next();
        if (current_node == nullptr) {
            std::cout << std::endl;
            return;
        }
    }
    std::cout << "chain is empty" << std::endl;
}