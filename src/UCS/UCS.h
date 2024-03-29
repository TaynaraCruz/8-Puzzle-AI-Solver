#ifndef UCS_H
#define UCS_H

#include "../Puzzle/Node.h"
#include "../Puzzle/Puzzle.h"


int UCS(Puzzle* puzzle, Node *State);

class ComparatorUCS{
    public:
        bool operator ()(const std::pair<int, int> &n1, const std::pair<int, int> &n2) const{
            return n1.second < n2.second;    
        }
};

#endif