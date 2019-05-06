#include <deque>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "BFS.h"

int BFS(Puzzle* puzzle, Node *State){

    std::deque <Node*> Frontier;/*Push back - Pop front*/
    std::unordered_set<int> Explored;
    
    Frontier.push_back(State);
    Node *curr = Frontier.front();
    
    //Goal test
    if(puzzle->check_solution(curr->state)){
        std::cout<<"Explored states: "<<Explored.size()<<std::endl;
        return curr->curr_cost;
    } 
    
    while(!Frontier.empty()){
        
        curr = Frontier.front();
        Explored.insert(curr->intg_node);
        Frontier.pop_front();
        
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
            auto q = std::find(Frontier.begin(),Frontier.end(), curr->children[i]);
            
            if(Explored.find(curr->children[i]->intg_node) == Explored.end() &&  q == Frontier.end()){
            
                //Goal test
                if(puzzle->check_solution(curr->children[i]->state)){
                    std::cout<<"Explored states: "<<Explored.size()<<std::endl;
                    return curr->children[i]->curr_cost;
                } 
                
                Frontier.push_back(curr->children[i]);
            }
            else delete curr->children[i];
        }
        
    }

    return -1; //This means faliure
}