#include "TicTacToe.h"

TicTacToe& TicTacToe::makeMove(TicTacToeMove move) {
    if (board->isLegal(move)) {
        TicTacToeBoard newBoard = board->makeMove(move);
        TicTacToeBoard* b1 = new TicTacToeBoard(newBoard);
        // In order to change b, it must first release the object to which it is pointing
        board.release();
        board = static_cast<std::unique_ptr<TicTacToeBoard>>(b1);
        ++turn;
    }
    else{
        throw std::invalid_argument("Illegal move!");
    }
    return *this;
}
