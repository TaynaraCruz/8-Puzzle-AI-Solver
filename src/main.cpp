#include <iostream>
#include <string>
#include "BFS/BFS.h"

std::string 

int main(int argc, char*agrv[]){

    //Start Puzzle
    Puzzle *puzzle = new Puzzle();
    Node *Inital_state = new Node();


    //I want to calculate the number of steps to reach the solution
    int num_steps = 0;
    
    num_steps = BFS(puzzle, Inital_state);

    if(num_steps >= 0) std::cout<<"Solution: "<<num_steps<<std::endl;
    else std::cout<<"There's No Solution"<<std::endl;

    delete Inital_state;
    delete puzzle;

    return 0;

}

void ParseArgs(int argc, char*argv[]){
    for(int i = 1; i < argc; i++){
        std::string arg = argv[i];

        if(arg == "-BFS"){

        }
    }
}