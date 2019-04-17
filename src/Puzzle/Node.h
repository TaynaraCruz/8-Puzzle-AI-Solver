#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include "Puzzle.h"

class Node{
    public:
        int** state;
        std::vector<Node> children;
        Node *parent;
        int curr_cost;

        Node();
        Node(Node *parent);
        ~Node();
        void Add_child(Node child);


};


#endif