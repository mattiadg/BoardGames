#include <stdexcept>
#include "ConnectXBoard.h"

int ConnectXBoard::numOccupied() const {
    auto ctr = 0;
    for (auto c : d) {
        if (c != '.')
            ++ctr;
    }
    return ctr;
}

ConnectXBoard ConnectXBoard::makeMove(ConnectxMove move) {
    if (isLegal(move)){
        auto newDescr(d);
        auto changedPos = findFirstFreePositionInCol(move.col);
        newDescr[changedPos] = move.symbol;
        return ConnectXBoard(newDescr);
    } else {
        throw std::invalid_argument("Received a bad move!");
    }
}

int ConnectXBoard::findFirstFreePositionInCol(int c) const {
    auto lastPositionInCol = c + (BOARD_SIZE -1) * BOARD_SIZE;
    while (lastPositionInCol >= 0){
        if (d[lastPositionInCol] == '.')
            return lastPositionInCol;
        else
            lastPositionInCol -= BOARD_SIZE;
    }
    throw std::invalid_argument("Column is not free!");
}

bool ConnectXBoard::isLegal(ConnectxMove move) const {
    if (move.col < 0 || move.col >= BOARD_SIZE)
        return false;
    if (d[move.col] != '.')
        return false;
    return true;
}

int ConnectXBoard::checkRow(int row) const {
    auto start = row * BOARD_SIZE;
    return checkLine(start, 1, start + BOARD_SIZE);
}

int ConnectXBoard::checkCol(int col) const {
    return checkLine(col, BOARD_SIZE, BOARD_SIZE*BOARD_SIZE);
}

int ConnectXBoard::checkDiagonals() const {
    // Diagonal 1
    auto diag1 = checkLine(0, BOARD_SIZE + 1, BOARD_SIZE * BOARD_SIZE);
    if (diag1 == 0){
        return checkLine(BOARD_SIZE - 1, BOARD_SIZE - 1, BOARD_SIZE * BOARD_SIZE);
    } else {
        return diag1;
    }
}

int ConnectXBoard::checkLine(int start, int increment, int topend) const {
    if (d[start] == '.'){
        return 0; //Not winning line
    }
    auto ctr = start + increment;
    while (ctr < topend){
        if (d[start] != d[ctr])
            return 0;
        ctr += increment;
    }
    if (d[start] == symbols[0]){
        return 1;
    } else {
        return -1;
    }
}

std::ostream & operator<<(std::ostream & os, const ConnectXBoard & board) {
    for (auto i = 0; i < BOARD_SIZE*BOARD_SIZE; ++i){
        os << board.getDescriptor()[i];
        if (i % BOARD_SIZE == BOARD_SIZE - 1)
            os << std::endl;
        else
            os << " ";
    }
}

GameState ConnectXBoard::getGameState() const {
    for (auto i = 0; i < BOARD_SIZE; ++i) {
        auto score = checkRow(i);
        if ( score != 0 )
            return scoreToGameState(score);
    }
    for (auto i = 0; i < BOARD_SIZE; ++i){
        auto score = checkCol(i);
        if ( score != 0 )
            return scoreToGameState(score);
    }
    return scoreToGameState(checkDiagonals());
}

inline
GameState ConnectXBoard::scoreToGameState(int score) const {
    if (score == 1)
        return Win1;
    if (score == -1)
        return Win2;
    if (numOccupied() < BOARD_SIZE*BOARD_SIZE)
        return Continue;
    return Draw;
}