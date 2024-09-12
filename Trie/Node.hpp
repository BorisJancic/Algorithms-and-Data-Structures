

#ifndef __NODE__
#define __NODE__


class Node {
    private:
        Node *nodes[26];
        bool word_end;
    public:
        Node();
        ~Node();
        void set_word_end(bool end);
        Node** get_nodes();
        Node* get_letter_node(int index);
        bool get_word_end();
};



#endif // NODE
