#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_set>

#include "HillClimbing.h"

int get_min_Hill(std::map<int, int> Frontier){
    
    std::pair<int, int> min = *std::min_element(Frontier.begin(), Frontier.end(), ComparatorHillClimbing());
    
    return min.first;
}


int HillClimbing(Puzzle* puzzle, Node *State, int k){

    /*Priority queue*/
    std::map <int, int> Solution_space;
    std::map<int, Node*> Solution_space_map;

    std::unordered_set <int> Explored;

    State->set_heuristic("Greedy");
    State->convert_node(); 
    Node* curr = State;
    Node* neighbor = State;  
    int limit = 0;

    while(limit <= k){
        
        Explored.insert(curr->intg_node);

        //Goal
        if(puzzle->check_solution(curr->state)) {
            std::cout<<"Explored states: "<<Explored.size()<<std::endl;
            return curr->curr_cost;
        }
        /**************************Actions***********************/
        
        Node* child1 = new Node(curr);
        puzzle->move_right(child1->state,curr->state);
        child1->convert_node();//convert array into integer
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
            auto q = Solution_space.find(curr->children[i]->intg_node);
            if(Explored.find(curr->children[i]->intg_node) == Explored.end() && q == Solution_space.end()){
                
                Solution_space[curr->children[i]->intg_node] = curr->children[i]->heuristic;
                Solution_space_map[curr->children[i]->intg_node] = curr->children[i];
            }
            else if(q != Solution_space.end()){//if child is in frontier with a higher heuristic cost, replace it
                if(Solution_space_map[q->first]->curr_cost > curr->children[i]->heuristic) {
                    Solution_space_map[q->first] = curr->children[i];
                }
            }
            else delete curr->children[i];
        }

        int min = get_min_Hill(Solution_space);

        neighbor = Solution_space_map[min];
        Solution_space.erase(neighbor->intg_node);
        Solution_space.erase(neighbor->intg_node);

        while(neighbor->heuristic > curr->heuristic && !Solution_space.empty()){
        
            min = get_min_Hill(Solution_space);

            neighbor = Solution_space_map[min];
            Solution_space.erase(neighbor->intg_node);
            Solution_space.erase(neighbor->intg_node);
            Explored.insert(neighbor->intg_node);

        }
        if(neighbor->heuristic < curr->heuristic) curr = neighbor;
        else if(neighbor->heuristic == curr->heuristic){//shoulder
            curr = neighbor;
            limit++;
        }
        else{
            break; //This means faliure
        };
        
    }
    return -1; //This means faliure
}