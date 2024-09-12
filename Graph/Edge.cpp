#include "Edge.hpp"

Edge::Edge(int source, int dest, int weight) {
    this->source = source;
    this->dest = dest;
    this->weight = weight;
}
Edge::~Edge() {}

void Edge::set_source(unsigned source) { this->source = source; }
void Edge::set_dest(unsigned dest) { this->dest = dest; }
void Edge::set_weight(unsigned weight) { this->weight = weight; }

int Edge::get_source() { return source; }
int Edge::get_dest() { return dest; }
int Edge::get_weight() { return weight; }
