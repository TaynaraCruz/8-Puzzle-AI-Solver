#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include "Puzzle.h"

class Node{
    public:
        int state[N][N];
        Node * parent;
        int curr_cost;

        Node();
        Node(Node *parent);
};

#endif