#include "../engine/TicTacToePlayer.h"
#include "../backend/TicTacToeBoardDescriptor.h"
#include "../backend/TicTacToeBoard.h"

#include "../../Catch/catch.hpp"

TEST_CASE("Test Tictactoe Player class")
{
	SECTION("player symbol is x")
	{
		char symbol = 'x';
		CHECK_NOTHROW(TicTacToePlayer(symbol));
	}

	SECTION("player symbol is o")
	{
		char symbol = 'o';
		CHECK_NOTHROW(TicTacToePlayer(symbol));
	}

	SECTION("player symbol is invalid")
	{
		char symbol = 'a';
		CHECK_THROWS(TicTacToePlayer(symbol));
	}
}

TEST_CASE("test play returns correct moves")
{
	SECTION("makes correct choice between blocking and winning")
	{
		TicTacToeBoardDescriptor desc("x.xox.oo.");
		TicTacToeBoard board(desc);
		TicTacToePlayer engine('o');

		REQUIRE(engine.play(board).i == 8);
	}

	SECTION("makes choice to block 1")
	{
		TicTacToeBoardDescriptor desc("x..x.o...");
		TicTacToeBoard board(desc);
		TicTacToePlayer engine('o');

		REQUIRE(engine.play(board).i == 6);
	}

	SECTION("makes choice to block 2")
	{
		TicTacToeBoardDescriptor desc("oxo.x...x");
		TicTacToeBoard board(desc);
		TicTacToePlayer engine('o');

		REQUIRE(engine.play(board).i == 7);
	}

	SECTION("makes choice to win 1")
	{
		TicTacToeBoardDescriptor desc("oo..x..x.");
		TicTacToeBoard board(desc);
		TicTacToePlayer engine('o');

		REQUIRE(engine.play(board).i == 2);
	}

	SECTION("makes choice to win 2")
	{
		TicTacToeBoardDescriptor desc("oxx.o.oxx");
		TicTacToeBoard board(desc);
		TicTacToePlayer engine('o');

		CHECK(engine.play(board).i == 3);
	}
}