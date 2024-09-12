#include <iostream>
#include <fstream>
#include "Graph.hpp"
#include "MinHeap.hpp"
#include "Node.hpp"
#include "Edge.hpp"
#include "illegal_exception.hpp"


Graph::Graph() {
    adjList = new Node*[50000];
    for (int i = 0; i < 50000; i++) {
        adjList[i] = nullptr;
        vertices[i] = false;
    }
}
Graph::~Graph() {
    for (int i = 0; i < 50000; i++) {
        Node* current = adjList[i];
        while (current != nullptr) {
            Node* tmp = current;
            current = current->get_next();
            delete tmp;
        }
        adjList[i] = nullptr;
    }
    delete[] adjList;
}

void Graph::load(std::string filename) {
    std::ifstream inputFile(filename);
    int i;
    inputFile >> i;
    while (inputFile.good()) {
        int a, b, w;
        inputFile >> a >> b >> w;
        insert(a, b, w, false);
    }
    std::cout << "success" << std::endl;
}
void Graph::insert(int a, int b, int w, bool print) {
    if (a < 1 || a > 50000 || b < 1 || b > 50000 || w <= 0 || a == b)
        throw illegal_exception();
    vertices[a-1] = true;
    vertices[b-1] = true;

    Node* current = adjList[a-1];
    while (current != nullptr) {
        if (current->get_vertex() == b) {
            if (print)
                std::cout << "failure" << std::endl;
            return;
        }
        current = current->get_next();
    }
    Edge* edge_a_b = new Edge(a, b, w);
    Edge* edge_b_a = new Edge(b, a, w);
    adjList[a-1] = new Node(b, w, adjList[a-1], edge_a_b);
    adjList[b-1] = new Node(a, w, adjList[b-1], edge_b_a);
    if (print)
        std::cout << "success" << std::endl;
}
void Graph::print(int a) {
    if (a < 1 || a > 50000)
        throw illegal_exception();

    Node* current = adjList[a-1];
    if (vertices[a-1] == false) {
        std::cout << "failure" << std::endl;
        return;
    }
    while (current != nullptr) {
        std::cout << current->get_vertex() << " ";
        current = current->get_next();
    }
    std::cout << std::endl;
}
void Graph::delete_vertex(int a) {
    if (a < 1 || a > 50000)
        throw illegal_exception();
    if (!adjList[a-1] && vertices[a-1]) {
        vertices[a-1] = false;
        std::cout << "success" << std::endl;
        return;
    }
    vertices[a-1] = false;
    Node* current = adjList[a-1];
    if (!current) {
        std::cout << "failure" << std::endl;
        return;
    }
    while (current != nullptr) {
        Node* current_vertex = adjList[current->get_vertex()-1];
        if (current_vertex->get_vertex() == a) {
            Node* tmp = current_vertex;
            adjList[current->get_vertex()-1] = current_vertex->get_next();
            delete tmp;
        } else {
            while (current_vertex->get_next() != nullptr) {
                if (current_vertex->get_next()->get_vertex() == a) {
                    Node* tmp = current_vertex->get_next();
                    current_vertex->set_next(current_vertex->get_next()->get_next());
                    delete tmp;
                    break;
                }
                current_vertex = current_vertex->get_next();
            }
        }
        Node* tmp = current;
        current = current->get_next();
        delete tmp;
    }
    adjList[a-1] = nullptr;
    std::cout << "success" << std::endl;
}
void Graph::MST() {
    MinHeap Q;
    bool visited[50000];
    for (int i = 0; i < 50000; i++) { visited[i] = false; }
    for (int i = 0; i < 50000; i++) {
        if (vertices[i]) {
            visited[i] = true;
            Node* current = adjList[i];
            while (current) {
                Q.insert(current->get_edge());
                current = current->get_next();
            }
            break;
        }
    }
    if (Q.is_empty()) { std::cout << "failure" << std::endl; return; }
    while (!Q.is_empty()) {
        Edge* current = Q.get_head();
        Q.pop_head();

        if (!visited[current->get_dest()-1]) {
            Node* vertex = adjList[current->get_dest()-1];
            while (vertex) {
                if (!visited[vertex->get_vertex()-1]) {
                    Q.insert(vertex->get_edge());
                }
                vertex = vertex->get_next();
            }
            visited[current->get_dest()-1] = true;
            std::cout << current->get_source() << " " << current->get_dest();
            std::cout << " " << current->get_weight() << " ";
        }
    }
    std::cout << std::endl;
}
void Graph::cost() {
    int weight = 0;
    MinHeap Q;
    bool visited[50000];
    for (int i = 0; i < 50000; i++) { visited[i] = false; }
    for (int i = 0; i < 50000; i++) {
        if (vertices[i]) {
            visited[i] = true;
            Node* current = adjList[i];
            while (current){
                Q.insert(current->get_edge());
                current = current->get_next();
            }
            break;
        }
    }
    if (Q.is_empty()) {
        std::cout << "cost is 0" << std::endl;
        return;
    }
    while (!Q.is_empty()) {
        Edge* current = Q.get_head();
        Q.pop_head();

        if (!visited[current->get_dest()-1]) {
            Node* vertex = adjList[current->get_dest()-1];
            while (vertex) {
                if (!visited[vertex->get_vertex()-1]) {
                    Q.insert(vertex->get_edge());
                }
                vertex = vertex->get_next();
            }
            visited[current->get_dest()-1] = true;
            weight += current->get_weight();
        }
    }
    std::cout << "cost is " << weight << std::endl;
}

