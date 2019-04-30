#include <list>
#include "BFS.h"

bool check(std::list<Node*> Frontier, Node *State){
    
    std::list<Node*>::iterator it;
    
    for(it=Frontier.begin(); it!=Frontier.end(); ++it){
        
        bool found = true;//stop checking if one element is different
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){

                if((*it)->state[i][j] != State->state[i][j]){
                    found = false;
                    break;
                }
            }
            if(!found) break;
        }

        if(found) return true;
    }
    return false;
}



int BFS(Puzzle* puzzle, Node *State){

    std::list<Node*> Frontier;/*Push back - Pop front*/
    std::list<Node*> Explored;/*Push back*/
    
    Frontier.push_back(State);
    Node *curr = Frontier.front();

    //Goal test
    if(puzzle->check_solution(curr->state)) return curr->curr_cost;
    
    while(!Frontier.empty()){
        
        curr = Frontier.front();

        Explored.push_back(curr);
        Frontier.pop_front();
        
        /**************************Actions***********************/
        
        Node* child1 = new Node(curr);
        puzzle->move_right(child1->state,curr->state);
        curr->Add_child(child1);

        Node* child2 = new Node(curr);
        puzzle->move_left(child2->state,curr->state);
        curr->Add_child(child2);

        Node* child3 = new Node(curr);
        puzzle->move_up(child3->state,curr->state);
        curr->Add_child(child3);

        Node* child4 = new Node(curr);
        puzzle->move_down(child4->state,curr->state);
        curr->Add_child(child4);

        /**************************Check***********************/

        for(int i = 0; i < (int)curr->children.size(); i++){
            
            if(!check(Explored, curr->children[i]) && !check(Frontier, curr->children[i])){
            
                //Goal test
                if(puzzle->check_solution(curr->children[i]->state)) return curr->children[i]->curr_cost;
                
                Frontier.push_back(curr->children[i]);
            }
            else delete curr->children[i];
        }
        
    }

    return -1; //This means faliure
}