#ifndef _PUZZLE_H_
#define _PUZZLE_H_

// N = 3 => 8-puzzle, N = 4 => 15-puzzle, N = 5 => 24-puzzle,... 
const int N = 3;

class Puzzle{
    private:
        int puzzle_solution[N][N];
    public:
        Puzzle();
        bool check_solution(int curr_solution[N][N]);

        int** move_right(int curr_state[N][N]);
        int** move_left(int curr_state[N][N]);
        int** move_up(int curr_state[N][N]);
        int** move_down(int curr_state[N][N]);
};

#endif