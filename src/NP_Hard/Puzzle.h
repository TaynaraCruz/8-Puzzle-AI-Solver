#ifndef _PUZZLE_H_
#define _PUZZLE_H_
#include <string>
// N = 3 => 8-puzzle, N = 4 => 15-puzzle, N = 5 => 24-puzzle,... 
#define N 3

class Puzzle{
    private:
        static int puzzle_solution[N][N];
        static void find_right_place(int &lin, int &col, int elem);//for manhattan distance heuristic
    public:
        Puzzle();
        bool check_solution(int curr_solution[N][N]);

        void move_right(int new_state[N][N], int curr_state[N][N]);
        void move_left(int new_state[N][N], int curr_state[N][N]);
        void move_up(int new_state[N][N], int curr_state[N][N]);
        void move_down(int new_state[N][N], int curr_state[N][N]);

        static int calculate_heuristic(int curr_solution[N][N], std::string type);//Heuristic
};

#endif