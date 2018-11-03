#include "../../Catch/catch.hpp"

#include "../backend/TicTacToe.h"

#include <string>

TEST_CASE("TicTacToe sets up correct values")
{
	SECTION("Default")
	{
		TicTacToe game;
		auto board = game.getBoard();

		CHECK(board.getDescriptor().getDescription() == ".........");
		CHECK(board.getGameState() == Continue);
		CHECK(game.getTurn() == 0);
	}

	SECTION("Draw")
	{
		TicTacToeBoardDescriptor desc("oxooxxxoo");
		TicTacToeBoard board(desc);

		TicTacToe* game = new TicTacToe(board);

		auto newboard = game->getBoard();

		CHECK(newboard.getDescriptor().getDescription() == "oxooxxxoo");
		CHECK(board.getGameState() == Draw);
	}

	SECTION("Win1")
	{
		TicTacToeBoardDescriptor desc("xxxoxxxoo");
		TicTacToeBoard board(desc);

		TicTacToe* game = new TicTacToe(board);

		auto newboard = game->getBoard();

		CHECK(newboard.getDescriptor().getDescription() == "xxxoxxxoo");
		CHECK(board.getGameState() == Win1);
	}

	SECTION("Win2")
	{
		TicTacToeBoardDescriptor desc("xxooooxoo");
		TicTacToeBoard board(desc);

		TicTacToe* game = new TicTacToe(board);

		auto newboard = game->getBoard();

		CHECK(newboard.getDescriptor().getDescription() == "xxooooxoo");
		CHECK(board.getGameState() == Win2);
	}
}

TEST_CASE("makemove")
{
	SECTION("valid move")
	{
		int row = 0;
		int col = 1;
		int symbol = 'x';

		TicTacToeMove move(row, col, symbol);
		TicTacToe game;
		
		CHECK_NOTHROW(game.makeMove(move));
		CHECK(game.getBoard().getGameState() == Continue);
		CHECK(game.getBoard().getDescriptor().getDescription() == ".x.......");
		CHECK(game.getTurn() == 1);
	}

	SECTION("Invalid move")
	{
		int row = 0;
		int col = 1;
		int symbol = 'x';

		TicTacToeBoardDescriptor desc(".x.......");
		TicTacToeBoard board(desc);
		TicTacToeMove move(row, col, symbol);

		TicTacToe* game = new TicTacToe(board);

		CHECK_THROWS(game->makeMove(move));
		CHECK(game->getBoard().getGameState() == Continue);
		CHECK(game->getBoard().getDescriptor().getDescription() == ".x.......");
	}
}