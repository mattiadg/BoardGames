#ifndef GAMES_TICTACTOEPLAYER_H
#define GAMES_TICTACTOEPLAYER_H

#include <stdexcept>
#include <vector>
#include <memory>
#include <climits>
#include "../backend/TicTacToeBoardDescriptor.h"
#include "../backend/TicTacToeBoard.h"

class Tree {
public:
    Tree(TicTacToeBoardDescriptor descriptor) :d(descriptor) {}
    void addChildren(Tree* c) {children.push_back(std::unique_ptr<Tree>(c));}
    void setValue(int v) {value = v; }
    int getValue() { return value; }
    bool hasChildren() { return children.size() != 0;}
    Tree& getChildren(int i){ return *children[i]; }
    const TicTacToeBoardDescriptor& getDescriptor() { return  d; }
    int numChildren () {return children.size();}
    int getLabel (int i) const { return labels[i]; }
    void setLabels(std::vector<int> ls) { labels = ls; }

private:
    const TicTacToeBoardDescriptor d;
    int value;
    std::vector<std::unique_ptr<Tree>> children;
    std::vector<int> labels;
};


class TicTacToePlayer {
public:
    TicTacToePlayer(char symbol) :assigned_simbol(symbol) {
        if (symbol != 'x' && symbol != 'o')
            throw std::invalid_argument("Not a valid symbol!");
    };
    TicTacToeMove play(const TicTacToeBoard&);
private:
    const char assigned_simbol;
    Tree& makeTree(Tree&, bool);
    TicTacToeMove generateMove(const TicTacToeBoardDescriptor&, char, std::vector<int>&);
};
int alphabeta(Tree& t, bool is_max=true, int alpha=INT_MIN, int beta=INT_MAX);
int findMoveInTree(Tree& t);
#endif //GAMES_TICTACTOEPLAYER_H
