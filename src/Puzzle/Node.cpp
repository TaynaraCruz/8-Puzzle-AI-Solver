#include <iostream>
#include <stdio.h>
#include <cmath>
#include "Node.h"

int Node::initial_state[N][N] {0};

void Node::set_initial(int initial[N][N]){
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            this->state[i][j] = initial[i][j];
        }
    }
}

void Node::convert_node(){
    int result = 0;
    int size = (N*N) -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            result += this->state[i][j]*(pow(10,size--));
        }
    }

    this->intg_node = result;
}

Node::Node(){

    FILE * pFile;
    pFile = fopen ("myfile.txt","r");
    //Fill from stdin
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            fscanf(pFile,"%i", &this->state[i][j]);
        }
    }
    fclose(pFile);

    this->parent = nullptr;
    this->curr_cost = 0;
    this->convert_node();
}

Node::Node(Node *parent){
    
    this->parent = parent;
    this->curr_cost = parent->curr_cost + 1;
    this->intg_node = 0;
}

void Node::Add_child(Node* child){
    this->children.push_back(child);
}
