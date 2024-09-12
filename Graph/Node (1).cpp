#include "Node.hpp"
#include "Edge.hpp"

Node::Node(unsigned vertex, unsigned weight, Node* next, Edge* edge) {
    this->vertex = vertex;
    this->weight = weight;
    this->next = next;
    this->edge = edge;
}
Node::~Node() {
    delete edge;
}

void Node::set_vertex(unsigned vertex) { this->vertex = vertex; }
void Node::set_weight(unsigned weight) { this->weight = weight; }
void Node::set_next(Node* next) { this->next = next; }
void Node::set_edge(Edge* edge) { this->edge = edge; }

unsigned Node::get_vertex() { return vertex; }
unsigned Node::get_weight() { return weight; }
Node* Node::get_next() { return next; }
Edge* Node::get_edge() { return edge; }
