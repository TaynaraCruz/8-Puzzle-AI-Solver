#ifndef ASTAR_H
#define ASTAR_H

#include "../Puzzle/Node.h"
#include "../Puzzle/Puzzle.h"

int Astar(Puzzle* puzzle, Node *State);

class ComparatorAstar{
    public:
        bool operator ()(const std::pair<int, int> &n1, const std::pair<int, int> &n2) const{
            return n1.second < n2.second;    
        }
};

#endif