#include <iostream>
#include "Node.h"

Node::Node(){
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            std::cin>>this->state[i][j];
        }
    }

    this->parent = nullptr;
    this->curr_cost = 0;
}

Node::Node(int state[N][N], Node *parent){
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            this->state[i][j] = state[i][j];
        }
    }

    this->parent = parent;
    this->curr_cost = parent->curr_cost + 1;
}

void Node::Add_child(Node child){
    this->children.push_back(child);
}
