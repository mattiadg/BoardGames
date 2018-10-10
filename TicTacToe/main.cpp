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
        try{
          d.makeMove(std::cin, curr_sym);
        }
        catch(std::invalid_argument e){
            std::cout << "Invalid input!\n";
            std::cout << e.what() << '\n';
        }
    }
    //TicTacToeBoard b2(std::string(""));
    //TicTacToeBoard(std::string("xox..cxox"));
    return 0;
}
