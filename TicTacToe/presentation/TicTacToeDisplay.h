#ifndef GAMES_TICTACTOEDISPLAY_H
#define GAMES_TICTACTOEDISPLAY_H

#include <iostream>
#include <memory>
#include "../backend/TicTacToeBoard.h"
#include "../backend/TicTacToe.h"

class TicTacToeDisplay {
public:
    TicTacToeDisplay(TicTacToe& game) :game(&game) {}
    friend std::ostream& display(std::ostream&, TicTacToeDisplay&);
    const TicTacToeDisplay& makeMove(std::istream&, char);

private:
    std::unique_ptr<TicTacToe> game;

};

#endif //GAMES_TICTACTOEDISPLAY_H
