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
        int intg_node;

        Node();
        Node(Node *parent);
        void Add_child(Node* child);
        void set_initial(int initial[N][N]);
        void convert_node();

       bool operator<(Node *n1){
           return this->intg_node < n1->intg_node;
       }
};
#endif
