#include "backend/TicTacToeBoard.h"
#include "presentation/TicTacToeDisplay.h"
#include <string>
#include <iostream>

int main() {
    TicTacToe game;
    TicTacToeDisplay d(game);
    while(game.getBoard().getGameState() == Continue) {
        char curr_sym = game.getTurn() % 2 == 0 ? 'x' : 'o';
        std::cout << game.getTurn() << std::endl;
        display(std::cout, d);
        d.makeMove(std::cin, curr_sym);
    }
    //TicTacToeBoard b2(std::string(""));
    //TicTacToeBoard(std::string("xox..cxox"));
    return 0;
}