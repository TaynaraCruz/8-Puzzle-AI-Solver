#include <iostream>
#include "Node.h"

Node::Node(){
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            std::cin>>this->state[i][j];
        }
    }

    this->parent = nullptr;
}

Node::Node(int state[N][N], Node *parent){
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            this->state[i][j] = state[i][j];
        }
    }

    this->parent = parent;
}

void Node::Add_child(Node child){
    this->children.push_back(child);
}
