#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>

#include "Node.h"

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

void Node::set_heuristic(std::string type){
    if(type == "Greedy") this->heuristic = Puzzle::calculate_heuristic(this->state, type);//h
    else if (type == "Astar") this->heuristic = Puzzle::calculate_heuristic(this->state, type) + this->curr_cost;// h + g
}

Node::Node(std::string file){

    FILE * pFile;
    file = "tests/" + file;
    
    pFile = fopen (file.c_str(),"r");
    if(pFile == NULL){
        std::cout<<"Error: invalid file"<<std::endl;
        return;
    }
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
    this->heuristic = 0;
}

Node::Node(Node *parent){
    
    this->parent = parent;
    this->curr_cost = parent->curr_cost + 1;
    this->intg_node = 0;
}

void Node::Add_child(Node* child){
    this->children.push_back(child);
}

