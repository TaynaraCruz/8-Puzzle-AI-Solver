#include <deque>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>
#include<set>
#include "GreedyBFS.h"


int get_min(std::map<int, int> Frontier){
    
    std::pair<int, int> min = *std::min_element(Frontier.begin(), Frontier.end(), ComparatorGreedy());
    
    return min.first;
}


int GreedyBFS(Puzzle* puzzle, Node *State){

    /*Priority queue*/
    std::map <int, int> Frontier;
    std::map<int, Node*> Frontier_map;
 
    std::unordered_set<int> Explored;
    
    State->set_heuristic("Greedy");

    Frontier[State->intg_node] = State->heuristic;
    Frontier_map[State->intg_node] = State;
    
    int min_node = get_min(Frontier);
    Node *curr = Frontier_map[min_node];
    
    //Goal test
    if(puzzle->check_solution(curr->state)) return curr->curr_cost;

    while(!Frontier.empty()){
        
        min_node = get_min(Frontier);
        curr = Frontier_map[min_node];
        Explored.insert(curr->intg_node);
        
        Frontier.erase(curr->intg_node);
        Frontier_map.erase(curr->intg_node);

        if(puzzle->check_solution(curr->state)) return curr->curr_cost;
        
        /**************************Actions***********************/
        
        Node* child1 = new Node(curr);
        puzzle->move_right(child1->state,curr->state);
        child1->convert_node();//convert array into 
        child1->set_heuristic("Greedy");//calculate the heuristic
        curr->Add_child(child1);

        Node* child2 = new Node(curr);
        puzzle->move_left(child2->state,curr->state);
        child2->convert_node();//convert array into integer
        child2->set_heuristic("Greedy");//calculate the heuristic
        curr->Add_child(child2);

        Node* child3 = new Node(curr);
        puzzle->move_up(child3->state,curr->state);
        child3->convert_node();//convert array into integer
        child3->set_heuristic("Greedy");//calculate the heuristic
        curr->Add_child(child3);

        Node* child4 = new Node(curr);
        puzzle->move_down(child4->state,curr->state);
        child4->convert_node();//convert array into integer
        child4->set_heuristic("Greedy");//calculate the heuristic
        curr->Add_child(child4);


        /**************************Check***********************/

        for(int i = 0; i < (int)curr->children.size(); i++){
            auto q = Frontier.find(curr->children[i]->intg_node);
            
            if(Explored.find(curr->children[i]->intg_node) == Explored.end() &&  q == Frontier.end()){
                
                Frontier[curr->children[i]->intg_node] = curr->children[i]->heuristic;
                Frontier_map[curr->children[i]->intg_node] = curr->children[i];
            }
            else delete curr->children[i];
        }
        
    }

    return -1; //This means faliure
}