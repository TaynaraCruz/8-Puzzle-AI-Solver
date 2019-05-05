#ifndef HILLCLIMBING_H
#define HILLCLIMBING_H

#include "../Puzzle/Node.h"
#include "../Puzzle/Puzzle.h"

int HillClimbing(Puzzle* puzzle, Node *State, int k);

class ComparatorHillClimbing{
    public:
        bool operator ()(const std::pair<int, int> &n1, const std::pair<int, int> &n2) const{
            return n1.second < n2.second;    
        }
};
#endif