#include <iostream>
#include <stdio.h>
#include "Node.h"

int Node::initial_state[N][N] {0};

void Node::set_initial(int initial[N][N]){
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            this->state[i][j] = initial[i][j];
        }
    }
}

Node::Node(){
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            this->state[i][j] = this->initial_state[i][j];
        }
    }
    
    this->parent = nullptr;
    this->curr_cost = 0;
}

Node::Node(Node *parent){
    
    this->parent = parent;
    this->curr_cost = parent->curr_cost + 1;
}

void Node::Add_child(Node* child){
    this->children.push_back(child);
}

