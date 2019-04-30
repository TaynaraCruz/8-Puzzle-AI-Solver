#include <iostream>
#include <stdio.h>
#include "Node.h"

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
}

Node::Node(Node *parent){
    
    this->parent = parent;
    this->curr_cost = parent->curr_cost + 1;
}
