#include <iostream>
#include <cmath>
#include <list>

#include "../Puzzle/Node.h"
#include "../Puzzle/Puzzle.h"


bool check(std::list<Node> Explored, Node State){
    bool explore = true;
    std::list<Node>::iterator it;
    for(it=Explored.begin(); it!=Explored.end(); ++it){
        bool explore = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(it->state[i][j] != State.state[i][j]) explore = false;
            }
        }
        if(explore) return true;
    }
    return false;
    
}

int BFS(Puzzle P, Node State){

    std::list<Node> Frontier;/*Push back - Pop front*/
    std::list<Node> Explored;/*Push back*/

    Frontier.push_back(State);
    Node curr = Frontier.front();
    
    while(1){
        if(Frontier.empty()) return -1; //This means faliure
        curr = Frontier.front();
        
        //Goal test
        if(P.check_solution(curr.state)){
            return curr.curr_cost;
        }

        Explored.push_back(curr);
        Frontier.pop_front();
        
        //Actions
        Node child1 = Node(&curr);
        P.move_right(child1.state,curr.state);
        if(!check(Explored, child1)&& !check(Frontier, child1) ){
            
            curr.Add_child(child1);
            Frontier.push_back(child1);
        }

        Node child2 = Node(&curr);
        P.move_left(child2.state,curr.state);
        if(!check(Explored, child2)&& !check(Frontier, child2)){
            
            curr.Add_child(child2);
            Frontier.push_back(child2);
        }
        
        Node child3 = Node(&curr);
        P.move_up(child3.state,curr.state);
        if(!check(Explored, child3)&& !check(Frontier, child3)){
            
            curr.Add_child(child3);
            Frontier.push_back(child3);
        }
        
        Node child4 = Node(&curr);
        P.move_down(child4.state,curr.state);
        if(!check(Explored, child4)&& !check(Frontier, child4)){
            
            curr.Add_child(child4);
            Frontier.push_back(child4);
        }


    }
}

int main(){

    //Start Puzzle
    Puzzle P = Puzzle();
    Node Inital_state = Node();


    //I want to calculate the number of steps to reach the solution
    int num_steps = 0;
    
    num_steps = BFS(P, Inital_state);

    if(num_steps >= 0) std::cout<<"Solution: "<<num_steps<<std::endl;
    else std::cout<<"There's No Solution"<<std::endl;


    return 0;

}