#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "BFS/BFS.h"
#include "UCS/UCS.h"
#include "IDS/IDS.h"
#include "GreedyBFS/GreedyBFS.h"
#include "Astar/Astar.h"
#include "HillClimbing/HillClimbing.h"

int main(int argc, char*argv[]){

    if(argc != 3){
        std::cout<<"Error: ./puzzle 'algorithm' 'file number'"<<std::endl;
        return 1;
    }

    std::cout<<std::fixed<<std::setprecision(5);
    
    //Start Puzzle
    Puzzle *puzzle = new Puzzle();
    Node *Inital_state = new Node(argv[2]);
    
    std::string func = argv[1];
    
    if(func == "BFS"){

        //I want to calculate the number of steps to reach the solution
        int num_steps = 0;
        auto start = std::chrono::steady_clock::now();//time
        num_steps = BFS(puzzle, Inital_state);

        if(num_steps >= 0) std::cout<<"Solution found! Number of movements: "<<num_steps<<std::endl;
        else std::cout<<"Could not find the solution"<<std::endl;
        
        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;

        std::cout <<"Time execution: "<< std::chrono::duration <double, std::milli> (diff).count() <<" ms"<< std::endl;

    }
    else if(func == "IDS"){
        
        int num_steps = 0;
        auto start = std::chrono::steady_clock::now();//time
        num_steps = IDS(puzzle, Inital_state);

        if(num_steps >= 0) std::cout<<"Solution found! Number of movements: "<<num_steps<<std::endl;
        else std::cout<<"Could not find the solution"<<std::endl;
        
        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;

        std::cout <<"Time execution: "<< std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
    }
    else if(func == "UCS"){
        
        int num_steps = 0;
        auto start = std::chrono::steady_clock::now();//time
        num_steps = UCS(puzzle, Inital_state);

        if(num_steps >= 0) std::cout<<"Solution found! Number of movements: "<<num_steps<<std::endl;
        else std::cout<<"Could not find the solution"<<std::endl;
        
        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;

        std::cout <<"Time execution: "<< std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
    }
    else if(func == "Astar"){
        
        int num_steps = 0;
        auto start = std::chrono::steady_clock::now();//time
        num_steps = Astar(puzzle, Inital_state);

        if(num_steps >= 0) std::cout<<"Solution found! Number of movements: "<<num_steps<<std::endl;
        else std::cout<<"Could not find the solution"<<std::endl;
        
        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;

        std::cout <<"Time execution: "<< std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
    }
    else if(func == "GreedyBFS"){
        
        int num_steps = 0;
        auto start = std::chrono::steady_clock::now();//time
        num_steps = GreedyBFS(puzzle, Inital_state);

        if(num_steps >= 0) std::cout<<"Solution found! Number of movements: "<<num_steps<<std::endl;
        else std::cout<<"Could not find the solution"<<std::endl;
        
        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;

        std::cout <<"Time execution: "<< std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
    }
    else if(func == "HillClimbing"){
        
        int num_steps = 0;

        int k;
        std::cout<<"side movements limit: ";
        std::cin>>k;
        auto start = std::chrono::steady_clock::now();//time
        num_steps = HillClimbing(puzzle, Inital_state, k);

        if(num_steps >= 0) std::cout<<"Solution found! Number of movements: "<<num_steps<<std::endl;
        else std::cout<<"Could not find the solution"<<std::endl;
        
        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;

        std::cout <<"Time execution: "<< std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
    }
    else
    {
        std::cout<<"Error: invalid algorithm"<<std::endl;
    }
    
    
    delete Inital_state;
    delete puzzle;

    return 0;

}