#include <iostream>
#include "Node.hpp"


class Graph {
    private:
        Node** adjList;
        bool vertices[50000];

    public:
        Graph();
        ~Graph();
        void load(std::string filename);
        void insert(int a, int b, int w, bool print=true);
        void print(int a);
        void delete_vertex(int a);
        void MST();
        void cost();
};
