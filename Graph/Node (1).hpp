#include "Edge.hpp"

#ifndef __NODE__
#define __NODE__

class Node {
    private:
        unsigned vertex;
        unsigned weight;
        Node* next;
        Edge* edge;

    public:
        Node(unsigned vertex, unsigned weight, Node* next, Edge* edge);
        ~Node();
        
        unsigned get_vertex();
        unsigned get_weight();
        Node* get_next();
        Edge* get_edge();

        void set_vertex(unsigned vertex);
        void set_weight(unsigned weight);
        void set_next(Node* next);
        void set_edge(Edge* edge);
};



#endif
