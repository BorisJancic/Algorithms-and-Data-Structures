#include <iostream>
#include <fstream>
#include "Node.hpp"

#ifndef __TRIE__
#define __TRIE__


class Trie {
    private:
        Node* head;
        unsigned size;

        unsigned count_DFS(Node* node);
        bool erase_DFS(Node* node, std::string &word, unsigned index);
        void print_DFS(Node* node, std::string &prefix);

    public:
        Trie();
        ~Trie();

        void load();
        void insert(std::string &word, bool print = true);
        void count(std::string &prefix);
        void erase(std::string &word);
        void print();
        void spellcheck(std::string &word);
        void empty();
        void clear();
        void get_size();
};



#endif // TRIE
