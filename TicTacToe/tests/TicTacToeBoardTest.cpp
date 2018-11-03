#include "../backend/TicTacToeBoard.h"

#include "../../Catch/catch.hpp"

// TESTS FOR TICTACTOEMOVE
TEST_CASE("Contstructor throws correct errors")
{
    SECTION("Correct , no errors")
    {
        int row = 1;
        int col = 1;
        char symbol = 'x';

		REQUIRE_NOTHROW(TicTacToeMove(row, col, symbol));
    }

	SECTION("Row invalid")
	{
		int row = 3;
		int col = 1;
		char symbol = 'x';

		CHECK_THROWS_AS(TicTacToeMove(row, col, symbol), std::invalid_argument);
	}

	SECTION("Col invalid")
	{
		int row = 1;
		int col = 3;
		char symbol = 'x';

		CHECK_THROWS_AS(TicTacToeMove(row, col, symbol), std::invalid_argument);
	}

	SECTION("Symbol invalid")
	{
		int row = 1;
		int col = 1;
		char symbol = 'a';

		CHECK_THROWS_AS(TicTacToeMove(row, col, symbol), std::invalid_argument);
	}

	SECTION("position invalid")
	{
		int pos = 9;
		char symbol = 'o';

		CHECK_THROWS_AS(TicTacToeMove(pos, symbol), std::invalid_argument);
	}
}


// TESTS FOR TICTACTOEBOARD
TEST_CASE("tests for makeMove && isLegal")
{
	SECTION("throws error when move is Illegal")
	{
		int pos = 5;
		char symbol = 'x';

		TicTacToeMove move(pos, symbol);
		TicTacToeBoardDescriptor desc("xxxxxxxxx");
		TicTacToeBoard board(desc);

		CHECK_THROWS_AS(board.makeMove(move), int);
	}

	SECTION("Returns false when move is not Legal")
	{
		int row = 1;
		int col = 1;
		char symbol = 'x';

		TicTacToeMove move(row, col, symbol);
		TicTacToeBoardDescriptor desc("xxxxxxxxx");
		TicTacToeBoard board(desc);

		CHECK(board.isLegal(move) == false);
	}

	SECTION("makeMove returns new Board with correct description")
	{
		int row = 1;
		int col = 1;
		char symbol = 'x';

		TicTacToeMove move(row, col, symbol);
		TicTacToeBoardDescriptor desc(".........");
		TicTacToeBoard board(desc);

		TicTacToeBoard nBoard = board.makeMove(move);

		CHECK(nBoard.getDescriptor().getDescription() != board.getDescriptor().getDescription());
		CHECK(nBoard.getDescriptor().getDescription() == "....x....");
	}
}

TEST_CASE("tests for getGameState")
{
	SECTION("returns correct state when x wins")
	{
		TicTacToeBoardDescriptor d1("xxx.oo.xo");
		TicTacToeBoard board(d1);

		CHECK(board.getGameState() == Win1);
	}

	SECTION("returns correct state when o wins")
	{
		TicTacToeBoardDescriptor d1("xx.ooo.xo");
		TicTacToeBoard board(d1);

		CHECK(board.getGameState() == Win2);
	}

	SECTION("returns correct state when draw")
	{
		TicTacToeBoardDescriptor d1("oxooxxxoo");
		TicTacToeBoard board(d1);

		CHECK(board.getGameState() == Draw);
	}

	SECTION("returns continue when game not finished")
	{
		TicTacToeBoardDescriptor d1("oxo.xx.oo");
		TicTacToeBoard board(d1);

		CHECK(board.getGameState() == Continue);
	}
}

TEST_CASE("tests for numOccupied")
{
	SECTION("returns 0")
	{
		TicTacToeBoardDescriptor d(".........");
		TicTacToeBoard board(d);

		CHECK(board.numOccupied() == 0);
	}

	SECTION("returns 8")
	{
		TicTacToeBoardDescriptor d("oxooxxxo.");
		TicTacToeBoard board(d);

		CHECK(board.numOccupied() == 8);
	}
}
