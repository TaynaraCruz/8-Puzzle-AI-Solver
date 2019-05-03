#include <iostream>
#include <string>
#include "BFS/BFS.h"
#include "UCS/UCS.h"
#include "IDS/IDS.h"

//std::string 

int main(){

    //Start Puzzle
    Puzzle *puzzle = new Puzzle();
    Node *Inital_state = new Node();


    //I want to calculate the number of steps to reach the solution
    int num_steps = 0;

    num_steps = IDS(puzzle, Inital_state);

    if(num_steps >= 0) std::cout<<"Solution: "<<num_steps<<std::endl;
    else std::cout<<"There's No Solution"<<std::endl;

    delete Inital_state;
    delete puzzle;

    return 0;

}