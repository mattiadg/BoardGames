#include "backend/TicTacToeBoard.h"
#include "presentation/TicTacToeDisplay.h"
#include "engine/TicTacToePlayer.h"
#include <string>
#include <iostream>

int main() {
    TicTacToe game;
    TicTacToeDisplay d(game);
    TicTacToePlayer engine('o');
    while(game.getBoard().getGameState() == Continue) {
        auto turn = game.getTurn();
        std::cout << "Turn: " << turn << std::endl;
        display(std::cout, d);
        char curr_sym = turn % 2 == 0 ? 'x' : 'o';
        if (turn % 2 == 0) {
            try {
                d.makeMove(std::cin, curr_sym);
            }
            catch (std::invalid_argument e) {
                std::cout << "Invalid input!\n";
                std::cout << e.what() << '\n';
            }
        } else {
            auto engine_move = engine.play(game.getBoard());
            game.makeMove(engine_move);
        }
    }
    return 0;
}
