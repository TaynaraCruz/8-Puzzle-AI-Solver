#include "Puzzle.h"

Puzzle::Puzzle(){//O(N²)

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
    return true;
}

void Puzzle::move_right(int new_state[N][N], int curr_state[N][N]){

    for(int i = 0; i <  N; i++){
        for(int j = 0; j < N; j++){
            if(curr_state[i][j]==0){
                if(j < N-1){
                    new_state[i][j] = curr_state[i][j+1];
                    new_state[i][j+1] = 0;
                    j++;
                }
                else new_state[i][j] = curr_state[i][j];
            }

            else new_state[i][j] = curr_state[i][j];
        }
    }

}
void Puzzle::move_left(int new_state[N][N], int curr_state[N][N]){
    
    for(int i = 0; i <  N; i++){
        for(int j = 0; j < N; j++){
            if(curr_state[i][j]==0){
                if(j > 0){
                    new_state[i][j] = curr_state[i][j-1];
                    new_state[i][j-1] = 0;
                }
                else new_state[i][j] = curr_state[i][j];
            }

            else new_state[i][j] = curr_state[i][j];
        }
    }

}
void Puzzle::move_up(int new_state[N][N], int curr_state[N][N]){
    
    for(int i = 0; i <  N; i++){
        for(int j = 0; j < N; j++){
            if(curr_state[i][j]==0){
                if(i > 0){
                    new_state[i][j] = curr_state[i-1][j];
                    new_state[i-1][j] = 0;
                }
                else new_state[i][j] = curr_state[i][j];
            }

            else new_state[i][j] = curr_state[i][j];
        }
    }

}
void Puzzle::move_down(int new_state[N][N], int curr_state[N][N]){
    int x = -1;
    int y = -1;

    for(int i = 0; i <  N; i++){
        for(int j = 0; j < N; j++){
            if(curr_state[i][j]==0){
                if(i < N-1){
                    new_state[i][j] = curr_state[i+1][j];
                    new_state[i+1][j] = 0;
                    y = i+1;
                    x = j;
                    
                }
                else new_state[i][j] = curr_state[i][j];
            }

            else if(y != i || x != j) new_state[i][j] = curr_state[i][j];
        }
    }

}