#include <iostream>
#include <cmath>
#include <queue>
#include <set>
#include <vector>

#include "../Puzzle/Node.h"
#include "../Puzzle/Puzzle.h"


bool check_explored(std::set<Node> Explored, Node elem){
    if(Explored.find(elem) != Explored.end()) return true;
    else return false;
}

int BFS(Puzzle P, Node State){
    
    int num_steps = 0;

    //Goal test
    if(P.check_solution(State.state)){
        return num_steps;
    }

    std::queue<Node> Frontier;
    std::set<Node> Explored;

    Frontier.push(State);

    while(1){
        if(Frontier.empty()) return -1; //This means faliure
        /*Node n = Frontier.pop();
        Explored.insert(n);
        int** state_child = P.move_right(n.state);
        Node child = Node(state_child, n);
        n.add_child(child);

        int** state_child = P.move_left(n.state);
        Node child = Node(state_child, n);
        n.add_child(child);
        if(child)

        int** state_child = P.move_up(n.state);
        Node child = Node(state_child, n);
        n.add_child(child);

        int** state_child = P.move_down(n.state);
        Node child = Node(state_child, n);
        n.add_child(child);

        */


    }



}

int main(){

    //Start Puzzle
    Puzzle P = Puzzle();
    Node Inital_state = Node();

    //I want to calculate the mininum number of steps to reach the solution
    int num_steps;

    num_steps = BFS(P, Inital_state);

    if(num_steps > 0) std::cout<<"Solution: "<<num_steps<<std::endl;
    else std::cout<<"There's No Solution"<<std::endl;


    return 0;

}