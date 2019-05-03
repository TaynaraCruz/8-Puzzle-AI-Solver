#ifndef UCS_H
#define UCS_H

#include "../Puzzle/Node.h"
#include "../Puzzle/Puzzle.h"

int UCS(Puzzle* puzzle, Node *State);

class Comparator{
    public:
        bool operator ()(const Node *n1, const Node *n2) const{
            return (-1)*n1->curr_cost < (-1)*n2->curr_cost;        
        }
};


#endif