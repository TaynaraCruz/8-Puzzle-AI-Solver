#include <iostream>
#include <cmath>
#include <list>
#include <unordered_set>

#include "../Puzzle/Node.h"
#include "../Puzzle/Puzzle.h"


bool check(std::list<Node*> Explored, Node *State){
    
    std::list<Node*>::iterator it;
    
    for(it=Explored.begin(); it!=Explored.end(); ++it){
        
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
        if(puzzle->check_solution(curr->state)){
            std::cout<<"\nExplored: "<<Explored.size()<<"\n";
            return curr->curr_cost;
        }
    
    while(!Frontier.empty()){
        
        curr = Frontier.front();

        Explored.push_back(curr);
        Frontier.pop_front();
        
        /**************************Actions***********************/
        Node* child1 = new Node(curr);
        puzzle->move_right(child1->state,curr->state);
        
        if(!check(Explored, child1) && !check(Frontier, child1)){
            
            //Goal test
            if(puzzle->check_solution(child1->state)){
                std::cout<<"\nExplored: "<<Explored.size()<<"\n";
                return child1->curr_cost;
            }
            
            Frontier.push_back(child1);
        }
        else delete child1;

        Node* child2 = new Node(curr);
        puzzle->move_left(child2->state,curr->state);
        if(!check(Explored, child2) && !check(Frontier, child2)){
            
            //Goal test
            if(puzzle->check_solution(child2->state)){
                std::cout<<"\nExplored: "<<Explored.size()<<"\n";
                return child2->curr_cost;
            }
            
            Frontier.push_back(child2);
        }
        else delete child2;
        
        Node* child3 = new Node(curr);
        puzzle->move_up(child3->state,curr->state);
        if(!check(Explored, child3)  && !check(Frontier, child3)){
            
            //Goal test
            if(puzzle->check_solution(child3->state)){
                std::cout<<"\nExplored: "<<Explored.size()<<"\n";
                return child3->curr_cost;
            }
            
            Frontier.push_back(child3);
        }
        else delete child3;
        
        Node* child4 = new Node(curr);
        puzzle->move_down(child4->state,curr->state);
        if(!check(Explored, child4) && !check(Frontier, child4)){
           
            //Goal test
            if(puzzle->check_solution(child4->state)){
                std::cout<<"\nExplored: "<<Explored.size()<<"\n";
                return child4->curr_cost;
            }
            
            Frontier.push_back(child4);
        }
        else delete child4;

    }

    return -1; //This means faliure
}

int main(){

    //Start Puzzle
    Puzzle *puzzle = new Puzzle();
    Node *Inital_state = new Node();


    //I want to calculate the number of steps to reach the solution
    int num_steps = 0;
    
    num_steps = BFS(puzzle, Inital_state);

    if(num_steps >= 0) std::cout<<"Solution: "<<num_steps<<std::endl;
    else std::cout<<"There's No Solution"<<std::endl;

    delete Inital_state;

    return 0;

}