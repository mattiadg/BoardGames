#include "backend/TicTacToeBoard.h"
#include "presentation/TicTacToeDisplay.h"
#include "engine/TicTacToePlayer.h"
#include <string>
#include <iostream>

int main() {
    TicTacToe game;
    TicTacToeDisplay d(game);

	  // Goal of the game
	  std::cout << "GOAL OF THE GAME:" << std::endl;
	  std::cout << std::endl;
	  std::cout << "The goal of the game is to get 3 of your symbols in a row. Be it horizontally, vertically or diagonally." 
              << std::endl;
	  std::cout << std::endl;

	  // Instructions
	  std::cout << "INSTRUCTIONS:" << std::endl;
	  std::cout << std::endl;
	  std::cout << "When prompted give 2 numbers between 0 and 2, which represent the row and column." 
              << std::endl;
	  std::cout << std::endl;
	  std::cout << "USAGE\tGive your next move (row, col): [row] [col]" << std::endl;

    bool player_go_first;
    std::cout << "Do you want to play first? [1:yes / 0:no]" << std::endl;
    std::cin >> player_go_first;
    char sym = player_go_first ? 'o' : 'x';
    TicTacToePlayer engine(sym);

    while(game.getBoard().getGameState() == Continue) {
        auto turn = game.getTurn();
		std::cout << std::endl;
        std::cout << "Turn: " << turn << std::endl;
        display(std::cout, d);
        char curr_sym = turn % 2 == 0 ? 'x' : 'o';
        if (turn % 2 == !player_go_first) {
            try {
				std::cout << "It is your turn." << std::endl;
				std::cout << "Give your next move (row, col): ";
				d.makeMove(std::cin, curr_sym);
				std::cout << std::endl;
            }
            catch (std::invalid_argument e) {
                std::cout << "Invalid input!\n";
                std::cout << e.what() << '\n';
            }
        } else {
			std::cout << "It is the computers turn." << std::endl;
            auto engine_move = engine.play(game.getBoard());
            game.makeMove(engine_move);
			std::cout << std::endl;
        }
    }
    return 0;
}
