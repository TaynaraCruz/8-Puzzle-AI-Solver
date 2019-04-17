#ifndef _PUZZLE_H_
#define _PUZZLE_H_

// N = 3 => 8-puzzle, N = 4 => 15-puzzle, N = 5 => 24-puzzle,... 
const int N = 3;

class Puzzle{
    private:
        int puzzle_solution[N][N];
    public:
        Puzzle();
        bool check_solution(int** curr_solution);

        void move_right(int** new_state, int** curr_state);
        void move_left(int** new_state, int** curr_state);
        void move_up(int** new_state, int** curr_state);
        void move_down(int** new_state, int** curr_state);
};

#endif