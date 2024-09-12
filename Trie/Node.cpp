#include "Node.hpp"

Node::Node() {
    word_end = false;
    for (int i = 0; i < 26; i++)
        nodes[i] = nullptr;
}

Node::~Node() {
    for (int i = 0; i < 26; i++)
        delete nodes[i];
}

void Node::set_word_end(bool end) {
    word_end = end;
}
Node** Node::get_nodes() {
    return nodes;
}
Node* Node::get_letter_node(int index) {
    return nodes[index];
}
bool Node::get_word_end() {
    return word_end;
}