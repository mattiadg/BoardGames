#ifndef GAMES_TICTACTOEBOARD_H
#define GAMES_TICTACTOEBOARD_H

#include "TicTacToeBoardDescriptor.h"
#include <stdexcept>
#include <string>

class TicTacToeMove {
public:
    TicTacToeMove(int row, int col, char symbol) :r(row), c(col), s(symbol), i(3 * r + c) {
        if (row < 0 || row > 2)
            throw std::invalid_argument("Invalid row " + row);
        if (col < 0 || col > 2)
            throw std::invalid_argument("Invalid col " + col);
        if (symbol != 'o' && symbol != 'x')
            throw std::invalid_argument("Invalid symbol " + symbol);
    }

    TicTacToeMove(int pos, char symbol) :TicTacToeMove(pos / 3, pos % 3, symbol) {
        if (pos < 0 || pos > 8)
            throw std::invalid_argument("Invalid pos " + pos);
    }

const int r;
const int c;
const int i;
const char s;
};

typedef enum {
    Continue, Win1, Win2, Draw
} GameState;

class TicTacToeBoard {
public:
    TicTacToeBoard() = default;
    TicTacToeBoard(const TicTacToeBoardDescriptor& desc) : d(desc) {}
    TicTacToeBoard(const TicTacToeBoard& oldBoard) :d(oldBoard.d) {}
    TicTacToeBoard(TicTacToeBoard&& oldBoard) :d(oldBoard.d) {}

    int numOccupied() const;
    GameState getGameState() const;

    const TicTacToeBoard makeMove(const TicTacToeMove& m) const;
    const TicTacToeBoardDescriptor& getDescriptor() const { return d;}
    bool isLegal(const TicTacToeMove& m) const;
    const char& operator[] (int i) const { return d[i];}
    const char& operator[] (int i) { return d[i];}

private:
    TicTacToeBoardDescriptor d;
    int checkLine(char, char, char) const;
};
#endif //GAMES_TICTACTOEBOARD_H
