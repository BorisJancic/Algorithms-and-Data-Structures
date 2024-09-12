#include "HashTable.hpp"
#include <iostream>

HashTable::HashTable(unsigned N, unsigned P) {
    memory = new int[N];
    page_size = P;
    table_size = N/P;
    current_size = 0;
    std::cout << "success" << std::endl;
}
HashTable::~HashTable() {
    delete[] memory;
    memory = nullptr;
}

unsigned HashTable::hash(unsigned k, unsigned i) {
    unsigned h1 = k%table_size;
    unsigned h2 = (k/table_size)%table_size;
    h2 = h2 | 1;
    return (h1 + i*h2)%table_size;
}
