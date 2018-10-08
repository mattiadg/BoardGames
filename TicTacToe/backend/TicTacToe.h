#ifndef GAMES_TICTACTOE_H
#define GAMES_TICTACTOE_H

#include <memory>
#include "TicTacToeBoard.h"

typedef enum {
    HUMAN, COMPUTER
} Player;

class TicTacToe {
public:
    TicTacToe() : board(new TicTacToeBoard()), turn(0) {}
    TicTacToe(TicTacToeBoard& otherBoard) :board(&otherBoard), turn(getTurn()) {}
    TicTacToe& makeMove(TicTacToeMove move);
    TicTacToeBoard& getBoard() { return *board;}
    char currentSymbol() { return symbols[turn%2]; }
    int getTurn() { return turn;}

private:
    std::unique_ptr<TicTacToeBoard> board;
    int turn;
    Player players[2] = {HUMAN, COMPUTER};
    static constexpr char symbols[2] = {'x', 'o'};
};
#endif //GAMES_TICTACTOE_H
