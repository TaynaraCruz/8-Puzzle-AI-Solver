#include <iostream>
#include <cmath>
#include <queue>
#include <set>

#include "../Puzzle/Node.h"
#include "../Puzzle/Puzzle.h"


bool check_explored(std::set<int**> Explored, int** state){
    bool explore = true;
    std::set<int**>::iterator it;
    for(it=Explored.begin(); it!=Explored.end(); ++it){
        bool explore = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if((*it)[i][j] != state[i][j]) explore = false;
            }
        }
        if(explore) return true;
    }
    return false;
    
}

int BFS(Puzzle P, Node State){

    std::queue<Node> Frontier;
    std::set<int**> Explored;

    Frontier.push(State);
    Node curr = Frontier.front();
    while(1){
        if(Frontier.empty()) return -1; //This means faliure
        curr = Frontier.front();
        
        //Goal test
        if(P.check_solution(curr.state)){
            return curr.curr_cost;
        }
        
        /*for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                std::cout<<curr.state[i][j]<<" ";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
        getchar();*/

        Explored.insert(curr.state);
        Frontier.pop();

        Node next1 = Node(&curr);
        
        P.move_right(next1.state,curr.state);
        if(!check_explored(Explored, next1.state)){
            Frontier.push(next1);
        }

        Node next2 = Node(&curr);
        P.move_left(next2.state,curr.state);
        if(!check_explored(Explored, next2.state)){
            Frontier.push(next2);
        }
        Node next3 = Node(&curr);
        P.move_up(next3.state,curr.state);
        if(!check_explored(Explored, next3.state)){
            Frontier.push(next3);
        }
        Node next4 = Node(&curr);
        P.move_down(next4.state,curr.state);
        if(!check_explored(Explored, next4.state)){
            Frontier.push(next4);
        }


    }
}

int main(){

    //Start Puzzle
    Puzzle P = Puzzle();
    Node Inital_state = Node();


    //I want to calculate the mininum number of steps to reach the solution
    int num_steps = 0;
    
    num_steps = BFS(P, Inital_state);

    if(num_steps >= 0) std::cout<<"Solution: "<<num_steps<<std::endl;
    else std::cout<<"There's No Solution"<<std::endl;


    return 0;

}