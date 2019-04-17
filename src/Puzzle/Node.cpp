#include <iostream>
#include <stdlib.h>
#include "Node.h"

Node::Node(){
    //Alocate memory
    this->state = new int* [N];
    for(int i = 0; i < N; i++){
        this->state[i] = new int[N];
    }

    //Fill from stdin
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            std::cin>>this->state[i][j];
        }
    }

    this->parent = nullptr;
    this->curr_cost = 0;
}

Node::Node(Node *parent){
    
    //Alocate memory
    this->state = new int* [N];
    for(int i = 0; i < N; i++){
        this->state[i] = new int[N];
    }

    this->parent = parent;
    this->curr_cost = parent->curr_cost + 1;
}

Node::~Node(){
    //Free memory
   /* for(int i = 0; i < N; i++){
        delete [] this->state[i];
    }
    delete [] this->state;
*/
}

void Node::Add_child(Node child){
    this->children.push_back(child);
}