#include <iostream>
#include "Trie.hpp"
#include "Node.hpp"
#include "illegal_exception.hpp"

Trie::Trie() {
    size = 0;
    head = new Node;
}

Trie::~Trie() {
    size = 0;
    delete head;
}

void Trie::load() {
    std::ifstream inputFile("corpus.txt");

    while (inputFile.good()) {
        std::string word;
        inputFile >> word;
        insert(word, false);
    }
    std::cout << "success" << std::endl;
}
void Trie::insert(std::string &word, bool print) {
    unsigned len = word.size();
    Node* current = head;

    for (unsigned i = 0; i < len; i++)
        if (word[i] < 'A' || word[i] > 'Z')
            throw illegal_exception();

    for (unsigned i = 0; i < len; i++) {
        if (current->get_letter_node(word[i] - 'A') == nullptr) {
            current->get_nodes()[word[i] - 'A'] = new Node();
        }
        current = current->get_letter_node(word[i] - 'A');
    }
    if (current->get_word_end() == false) {
        current->set_word_end(true);
        size += 1;
        if (print) std::cout << "success" << std::endl;
    } else {
        if (print) std::cout << "failure" << std::endl;
    }
}
void Trie::count(std::string &prefix) {
    Node* current = head;
    for (unsigned i = 0; i < prefix.size(); i++)
        if (prefix[i] < 'A' || prefix[i] > 'Z')
            throw illegal_exception();

    for (unsigned k = 0; k < prefix.size(); k++) {
        unsigned index = prefix[k] - 'A';
        if (current->get_nodes()[index] == nullptr) {
            std::cout << "not found" << std::endl;
            return;
        }
        current = current->get_nodes()[index];
    }

    int count = count_DFS(current);
    std::cout << "count is " << count << std::endl;
}

unsigned Trie::count_DFS(Node* node) {
    if (node == nullptr)
        return 0;
    
    unsigned count = 0;
    if (node->get_word_end() == true)
        count++;

    for (int i = 0; i < 26; i++)
        count += count_DFS(node->get_nodes()[i]);

    return count;
}

void Trie::erase(std::string &word) {
    for (unsigned i = 0; i < word.size(); i++)
        if (word[i] < 'A' || word[i] > 'Z')
            throw illegal_exception();

    Node* current = head;
    for (unsigned i = 0; i < word.size(); i++) {
        unsigned index = word[i] - 'A';

        if (current->get_nodes()[index] == nullptr) {
            std::cout << "failure" << std::endl;
            return;
        }
        current = current->get_nodes()[index];
    }
    bool prefix = false;
    for (unsigned i = 0; i < 26; i++) {
        if (current->get_nodes()[i] != nullptr) {
            prefix = true;
            break;
        }
    }

    if (current->get_word_end() == false) {
        std::cout << "failure" << std::endl;
        return; 
    }
    current->set_word_end(false);

    size--;
    if (prefix == true) {
        std::cout << "success" << std::endl;
        return; 
    }

    erase_DFS(head, word, 0);
    std::cout << "success" << std::endl;
}
bool Trie::erase_DFS(Node* node, std::string &word, unsigned index) {
    if (node == nullptr)
        return true;
    if (index == word.size())
        return true;

    unsigned i = word[index] - 'A';
    Node* current_node = node->get_nodes()[i];
    if (current_node == nullptr)
        return true;
    if (!erase_DFS(current_node, word, index + 1))
        return false;

    bool end_delete = false;
    for (unsigned k = 0; k < 26; k++)
        if (current_node->get_nodes()[k] != nullptr)
            end_delete = true;
    if (current_node->get_word_end() == true)
        end_delete = true;

    if (!end_delete) {
        delete current_node;
        node->get_nodes()[i] = nullptr;
    }
    return !end_delete;
}


void Trie::print() {
    if (size == 0)
        return;
    std::string word = "";
    print_DFS(head, word);
    std::cout << std::endl;
}

void Trie::print_DFS(Node* node, std::string &prefix) {
    if (node->get_word_end() == true)
        std::cout << prefix << " ";
    for (unsigned i = 0; i < 26; i++) {
        if (node->get_nodes()[i] != nullptr) {
            prefix.push_back('A' + i);
            print_DFS(node->get_nodes()[i], prefix);
            prefix.pop_back();
        }
    }
}

void Trie::spellcheck(std::string &word) {
    for (unsigned i = 0; i < word.size(); i++)
        if (word[i] < 'A' || word[i] > 'Z')
            throw illegal_exception();
    
    Node* current = head;
    unsigned end_index = 0;
    for (unsigned i = 0; i < word.size(); i++) {
        unsigned index = word[i] - 'A';
        if (current->get_nodes()[index] != nullptr) 
            current = current->get_nodes()[index];
        else break;
        end_index++;
    }
    
    if (current->get_word_end() == true && end_index == word.size()) {
        std::cout << "correct" << std::endl;
        return;
    } 
    std::string prefix = word.substr(0, end_index);
    if (prefix.size() == 0) {
        std::cout << std::endl;
        return;
    }
    print_DFS(current, prefix);
    std::cout << std::endl;
}

void Trie::empty() {
    if (size == 0) std::cout << "empty 1" << std::endl;
    else std::cout << "empty 0" << std::endl;
}

void Trie::clear() {
    for (unsigned i = 0; i < 26; i++) {
        delete head->get_nodes()[i];
        head->get_nodes()[i] = nullptr;
    }
    size = 0;
    std::cout << "success" << std::endl;
}

void Trie::get_size() {
    std::cout << "number of words is " << size << std::endl;
}