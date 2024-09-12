#include "Edge.hpp"
#include <vector>

class MinHeap {
    private:
        std::vector<Edge*> vect;
        void heapify();

    public:
        MinHeap();
        ~MinHeap();
        void insert(Edge* edge);
        Edge* get_head();
        void pop_head();
        bool is_empty();
};