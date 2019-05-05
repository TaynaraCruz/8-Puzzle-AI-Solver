#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include <string>

#include "Puzzle.h"

class Node{
    public:
        int state[N][N];
        Node * parent;
        int curr_cost;
        std::vector<Node*> children;
        int intg_node;//convert array into an integer
        int heuristic;


        Node(std::string file);
        Node(Node *parent);
        void Add_child(Node* child);
        void set_initial(int initial[N][N]);
        void convert_node();
        void set_heuristic(std::string type);
        
       bool operator<(Node *n1){
           return this->intg_node < n1->intg_node;
       }
};
#endif
