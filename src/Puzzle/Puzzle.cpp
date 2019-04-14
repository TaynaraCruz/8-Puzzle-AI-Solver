#include "Puzzle.h"

Puzzle::Puzzle(){//O(N²)
    
    this->solution = false;

    this->puzzle_solution[N-1][N-1] = 0;

    int k = 1;//1,2,3,...N-1
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            
            if(i != N-1 || j != N-1) this->puzzle_solution[i][j] = k++;
        }
    }
}

bool Puzzle::check_solution(int curr_solution[N][N]){ //O(N²)
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(this->puzzle_solution[i][j] != curr_solution[i][j]) return false;
        }
    }
    this->solution = true;
    return true;
}
