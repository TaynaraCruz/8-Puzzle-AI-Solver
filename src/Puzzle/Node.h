#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include "Puzzle.h"

class Node{
    public:
        static int initial_state[N][N];
        int state[N][N];
        Node * parent;
        int curr_cost;
        std::vector<Node*> children;

        Node();
        Node(Node *parent);
        void Add_child(Node* child);
        void set_initial(int initial[N][N]);

       
};
#endif
