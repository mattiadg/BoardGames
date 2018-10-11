#include "backend/TicTacToeBoard.h"
#include "presentation/TicTacToeDisplay.h"
#include "engine/TicTacToePlayer.h"
#include <string>
#include <iostream>

int main() {
    TicTacToe game;
    TicTacToeDisplay d(game);
    bool player_go_first;
    std::cout << "Do you want to play first? [1:yes / 0:no]" << std::endl;
    std::cin >> player_go_first;
    char sym = player_go_first ? 'o' : 'x';
    TicTacToePlayer engine(sym);
    while(game.getBoard().getGameState() == Continue) {
        auto turn = game.getTurn();
        std::cout << "Turn: " << turn << std::endl;
        display(std::cout, d);
        char curr_sym = turn % 2 == 0 ? 'x' : 'o';
        if (turn % 2 == !player_go_first) {
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
