#ifndef IDS_H
#define IDS_H


#include "../Puzzle/Node.h"
#include "../Puzzle/Puzzle.h"

int IDS(Puzzle* puzzle, Node *State);
int L_DFS(Puzzle* puzzle, Node *State, int limit);

#endif