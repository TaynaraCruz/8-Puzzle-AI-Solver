#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include "UCS.h"


bool check(std::unordered_map<int, int> Frontier_comp, std::priority_queue <Node*, std::vector<Node*>,Comparator> &Frontier, Node* node){
    Node* pop;
    bool found = false;

    std::unordered_map<int, int>::iterator it = Frontier_comp.find(node->intg_node);
    if(it != Frontier_comp.end()){
        if(it->second > node->curr_cost){
            std::priority_queue <Node*, std::vector<Node*>,Comparator> Frontier_aux;

            while(!Frontier.empty()){
                pop = Frontier.top();
                Frontier.pop();
                
                if(pop->intg_node == node->intg_node){
                    if(pop->curr_cost > node->curr_cost) pop = node;
                }

                Frontier_aux.push(node);
            }

            while(!Frontier_aux.empty()){
                pop = Frontier_aux.top();
                Frontier_aux.pop();
                Frontier.push(pop);
            }
        }
        found = true;
    }
    

    return found;
}


int UCS(Puzzle* puzzle, Node *State){

    std::priority_queue <Node*, std::vector<Node*>,Comparator> Frontier;
    std::unordered_map<int, int> Frontier_comp;

    std::unordered_set<int> Explored;
    
    Frontier.push(State);
    Frontier_comp[State->intg_node] = State->curr_cost;
    Node *curr = Frontier.top();
   
    
    while(!Frontier.empty()){
        
        curr = Frontier.top();
        Explored.insert(curr->intg_node);
        Frontier.pop();
        Frontier_comp.erase(curr->intg_node);
        
        //Goal test
        if(puzzle->check_solution(curr->state)) return curr->curr_cost;

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
            
            if(Explored.find(curr->children[i]->intg_node) == Explored.end() &&  !check(Frontier_comp, Frontier, curr->children[i])){
                
                Frontier.push(curr->children[i]);
                Frontier_comp[curr->children[i]->intg_node] = curr->children[i]->curr_cost;
            }
            else delete curr->children[i];
        }
        
    }

    return -1; //This means faliure
}