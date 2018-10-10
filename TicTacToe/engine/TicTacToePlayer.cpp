#include <vector>
#include <algorithm>
#include <iostream>
#include "TicTacToePlayer.h"

TicTacToeMove TicTacToePlayer::generateMove(const TicTacToeBoardDescriptor& board, char next_sym, std::vector<int>& generated){
    auto last = generated.size() > 0 ? generated.back() : -1;
    for (auto i = ++last; i < BOARD_SIZE; ++i){
        if (board[i] == '.'){
            generated.push_back(i);
            return TicTacToeMove(i, next_sym);
        }
    }
    throw 2; // Finished moves
}

TicTacToeMove treeSearch(Tree & t, char symbol, bool is_max=true){
    auto max_val = alphabeta(t, is_max);
    auto pos = findMoveInTree(t);
    std::cout << "Move: " << pos << std::endl;
    TicTacToeMove move(pos, symbol);
    return move;
}

int alphabeta(Tree& t, bool is_max, int alpha, int beta){
    if (!t.hasChildren()) { //if is leave
        return t.getValue();
    }
    std::vector<int> children_values;
    for (auto i = 0; i < t.numChildren(); ++i){
        auto val = alphabeta(t.getChildren(i), !is_max, alpha, beta);
        if (is_max)
            alpha = std::max(alpha, val);
        else
            beta = std::min(beta, val);

        if (alpha >= beta) {
            t.setValue(val);
            return val;
        }
        children_values.push_back(val);
    }
    auto thisVal = 0;
    if (is_max)
        thisVal = *(std::max_element(children_values.begin(), children_values.end()));
    else
        thisVal = *(std::min_element(children_values.begin(), children_values.end()));
    t.setValue(thisVal);
    return thisVal;
}

int findMoveInTree(Tree& t) {
    auto val = t.getValue();
    for (auto i = 0; i < t.numChildren(); ++i) {
        if (t.getChildren(i).getValue() == val)
            return t.getLabel(i);
    }
}

TicTacToeMove TicTacToePlayer::play(const TicTacToeBoard & board) {
    Tree playTree(board.getDescriptor());
    makeTree(playTree, assigned_simbol == 'x');
    bool is_first = board.numOccupied() == 0;
    auto move = treeSearch(playTree, assigned_simbol, is_first);
    return move;
}

Tree& TicTacToePlayer::makeTree(Tree & t, bool x) {
    std::vector<int> generatedMoves;
    auto d = t.getDescriptor();
    auto b = TicTacToeBoard (d);
    auto state = b.getGameState();
    switch (state){
        case Win1:
            t.setValue(10);
            return t;
        case Win2:
            t.setValue(-10);
            return t;
        case Draw:
            t.setValue(0);
            return t;
    }
    while(1){
        try {
            auto move = generateMove(b.getDescriptor(), x ? 'x' : 'o', generatedMoves);
            t.addChildren(new Tree(d.editDescription(move.i, move.s)));
        } catch (int e){ // Moves are finished
            break;
        }
    }
    t.setLabels(generatedMoves);
    for (auto i = 0; i < t.numChildren(); ++i){
        makeTree(t.getChildren(i), !x);
    }
    return t;
}