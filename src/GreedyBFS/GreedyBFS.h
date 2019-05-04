#ifndef GREEDYBFS_H
#define  GREEDYBFS_H

#include "../Puzzle/Node.h"
#include "../Puzzle/Puzzle.h"

int GreedyBFS(Puzzle* puzzle, Node *State);

class ComparatorGreedy{
    public:
        bool operator ()(const std::pair<int, int> &n1, const std::pair<int, int> &n2) const{
            return n1.second < n2.second;    
        }
};


#endif