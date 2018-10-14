#include "TicTacToeBoard.h"

const TicTacToeBoard TicTacToeBoard::makeMove(const TicTacToeMove& m) const {
    if (!isLegal(m))
        throw 1; // Illegal move

    auto newDescription = d.editDescription(m.i, m.s);
    TicTacToeBoard b(newDescription);
    return b;
}

bool TicTacToeBoard::isLegal(const TicTacToeMove &m) const {
    if (d[m.i] != '.')
        return false;
    return true;
}

GameState TicTacToeBoard::getGameState() const {
    auto str = d.getDescription();
    for (auto i = 0; i < BOARD_SIZE / 3; ++i) {
        auto state = checkLine(str[3 * i], str[3 * i + 1], str[3 * i + 2]);
        if (state == 0) {
            if (i == 0) {
                state = checkLine(str[0], str[4], str[8]);
            } else {
                if (i == 2) {
                    state = checkLine(str[2], str[4], str[6]);
                }
            }
        }
        if (state == 1)
            return Win1;
        else if (state == -1)
            return Win2;
    }
    for (auto i = 0; i < BOARD_SIZE / 3; ++i) {
        auto state = checkLine(str[i], str[i + 3], str[i + 6]);
        if (state == 1)
            return Win1;
        else if (state == -1)
            return Win2;
    }
    if (numOccupied() < 9)
        return Continue;
    return Draw;
}

int TicTacToeBoard::numOccupied() const  {
    auto occ = 0;
    for (auto c: d.getDescription())
        occ += (c != '.') ? 1 : 0;
    return occ;
}

int TicTacToeBoard::checkLine(char x, char y, char z) const {
    if (x == y && y == z && x == 'x')
        return 1;
    else{
        if (x == y && y == z && x == 'o')
            return -1;
        else
            return 0;
    }
}