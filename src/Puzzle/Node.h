#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include "Puzzle.h"

class Node{
    public:
        int state[N][N];
        std::vector<Node> children;
        Node *parent;

        Node();
        Node(int state[N][N], Node *parent);
        void Add_child(Node child);

};


#endif