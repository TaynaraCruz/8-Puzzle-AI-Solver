#include <list>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "IDS.h"

std::unordered_set<int> Explored;

int L_DFS_Rec(Puzzle* puzzle, Node *State, int limit, int cut_off){

    Node *curr = State;
    
    //Goal test
    if(puzzle->check_solution(curr->state)) return curr->curr_cost;
    else if (limit == 0) return cut_off;
    else{
        bool cut_off_occurred = false;
        Explored.insert(curr->intg_node);

    
        /**************************Actions***********************/
        
        Node* child1 = new Node(curr);
        puzzle->move_right(child1->state,curr->state);
        child1->convert_node();//convert array into integer
        curr->Add_child(child1);

        Node* child2 = new Node(curr);
        puzzle->move_left(child2->state,curr->state);
        child2->convert_node();//convert array into integer
        curr->Add_child(child2);

        Node* child3 = new Node(curr);
        puzzle->move_up(child3->state,curr->state);
        child3->convert_node();//convert array into integer
        curr->Add_child(child3);

        Node* child4 = new Node(curr);
        puzzle->move_down(child4->state,curr->state);
        child4->convert_node();//convert array into integer
        curr->Add_child(child4);


        /**************************Check***********************/
        
        for(int i = 0; i < (int)curr->children.size(); i++){
            int result = 0;

            if(Explored.find(curr->children[i]->intg_node) == Explored.end()) {

                result = L_DFS_Rec(puzzle, curr->children[i], limit-1, cut_off);
            }
            if(result == cut_off) cut_off_occurred = true;
            else if(result > 0) return result;
               
        }
        if(cut_off_occurred) return cut_off;
        else return -1;
    }
    
    
}

int L_DFS(Puzzle* puzzle, Node *State, int limit){
    int cut_off = limit+1;
    return L_DFS_Rec(puzzle, State, limit, cut_off);
    
}

int IDS(Puzzle* puzzle, Node *State){
    bool found = false;
    int result;
    int limit = 0;
    while(!found){
        result = L_DFS(puzzle, State, limit);
        if(result < limit+1) found = true;
       // std::cout<<"Limit: "<<limit<<" result: "<<result<<std::endl;
        limit++;
        Explored.clear();
    }
    return result;
    
}