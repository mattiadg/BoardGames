#include "TicTacToeDisplay.h"
#include <iostream>
#include <stdexcept>
#include <memory>

std::ostream & display(std::ostream &os, TicTacToeDisplay& d) {
    auto descr = d.game->getBoard();
    for (auto i = 0; i < 3; ++i){
        os << static_cast<char>(descr[i*3]) << "|" <<
           static_cast<char>(descr[i*3+1]) << "|" <<
           static_cast<char>(descr[i*3+2]) << std::endl;
        if (i < 2)
            os << "-|-|-" << std::endl;
    }
    return os;
}

const TicTacToeDisplay& TicTacToeDisplay::makeMove(std::istream &is, char symbol) {
    int r, c;
    is >> r;
    is >> c;
    game->makeMove(TicTacToeMove(r, c, symbol));
    return *this;
}