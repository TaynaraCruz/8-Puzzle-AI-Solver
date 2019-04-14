#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

#include "../Puzzle/Node.h"
#include "../Puzzle/Puzzle.h"


int BFS(Puzzle P, Node State){
    
}

int main(){

    //Start Puzzle
    Puzzle P = Puzzle();
    Node Inital_state = Node();

    //I want to calculate the mininum number of steps to reach the solution
    int num_steps;

    num_steps = BFS(P, Inital_state);

    if(P.solution) std::cout<<"Solution: "<<num_steps<<std::endl;
    else std::cout<<"There's No Solution"<<std::endl;


    return 0;

}