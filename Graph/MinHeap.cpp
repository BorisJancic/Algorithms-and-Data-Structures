#include <iostream>
#include "MinHeap.hpp"
#include "Edge.hpp"

MinHeap::MinHeap() {
    vect = {nullptr};
}
MinHeap::~MinHeap() {
    for (int i = 0; i < vect.size(); i++)
        delete vect[i];
}

void MinHeap::heapify() {
    int i = 1;
    while (i < vect.size()) {

        if (i*2 > vect.size()-1) { break; }
        if (vect[i]->get_weight() > vect[i*2]->get_weight() &&
            vect[i*2]->get_weight() < vect[i*2+1]->get_weight()) {
            Edge* tmp = vect[i];
            vect[i] = vect[i*2];
            vect[i*2] = tmp;
            i = i*2;
            continue;
        }
        if (i*2+1 > vect.size()-1) { break; }
        if (vect[i]->get_weight() > vect[i*2+1]->get_weight()) {
            Edge* tmp = vect[i];
            vect[i] = vect[i*2+1];
            vect[i*2+1] = tmp;
            i = i*2+1;
            continue;
        }
        break;
    }
}

void MinHeap::insert(Edge* edge) {
    vect.push_back(edge);

    unsigned i = vect.size()-1;

    while (i > 1) {
        if (vect[i]->get_weight() < vect[i/2]->get_weight()) {
            Edge* tmp = vect[i];
            vect[i] = vect[i/2];
            vect[i/2] = tmp;
        } else break;
        i = i/2;
    }
}
Edge* MinHeap::get_head() {
    if (vect.size() <= 1)
        return nullptr;
    return vect[1];
}
void MinHeap::pop_head() {
    if (vect.size() <= 1)
        return;
    vect[1] = vect.back();
    vect.pop_back();
    heapify();
}

bool MinHeap::is_empty() {
    if (vect.size() <= 1) {
        return true;
    } else {
        return false;
    }
}
