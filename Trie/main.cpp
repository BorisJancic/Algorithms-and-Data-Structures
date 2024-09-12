#include <iostream>
#include "Trie.hpp"
#include "illegal_exception.hpp"

int main() {
    std::string command = "";
    Trie* trie = new Trie;

    while (command != "exit") {
        try {
            std::cin >> command;
            if (command == "load") {
                trie->load();
            } else if (command == "i") {
                std::string word;
                std::cin >> word;
                trie->insert(word);
            } else if (command == "c") {
                std::string prefix;
                std::cin >> prefix;
                trie->count(prefix);
            } else if (command == "e") {
                std::string word;
                std::cin >> word;
                trie->erase(word);
            } else if (command == "p") {
                trie->print();
            } else if (command == "spellcheck") {
                std::string word;
                std::cin >> word;
                trie->spellcheck(word);
            } else if (command == "empty") {
                trie->empty();
            } else if (command == "clear") {
                trie->clear();
            } else if (command == "size") {
                trie->get_size();
            }
        } catch (illegal_exception &ex) {
            std::cout << "illegal argument" << std::endl;
        }
    }

    delete trie;

    return 0;
}
