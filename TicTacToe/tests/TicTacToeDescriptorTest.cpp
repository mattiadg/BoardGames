#include "../backend/TicTacToeBoardDescriptor.h"

#include <iostream>
#include <string>

#include "../../Catch/catch.hpp"


TEST_CASE("checking for correct error messages in descriptor")
{
	SECTION("descriptor is correct")
	{
		const std::string descriptor = ".x..o.x..";

		CHECK_NOTHROW(TicTacToeBoardDescriptor());
		CHECK_NOTHROW(TicTacToeBoardDescriptor(descriptor));
	}

	SECTION("descriptor is too short")
	{
		const std::string descriptor = "....";
		CHECK_THROWS(TicTacToeBoardDescriptor(descriptor));
	}

	SECTION("descriptor is too long")
	{
		const std::string descriptor = ".............";
		CHECK_THROWS(TicTacToeBoardDescriptor(descriptor));
	}

	SECTION("descriptor has invalid char")
	{
		const std::string descriptor = "........0";
		CHECK_THROWS_WITH(TicTacToeBoardDescriptor(descriptor), "Found invalid character in descriptor!");
	}

	SECTION("descriptor has only invalid char")
	{
		const std::string descriptor = "abcdefghj";
		CHECK_THROWS_WITH(TicTacToeBoardDescriptor(descriptor), "Found invalid character in descriptor!");
	}
}

TEST_CASE("test getDescription")
{
	TicTacToeBoardDescriptor ttd;

	SECTION("getDescription returns correct descriptor")
	{
		const std::string descriptor = ".........";
		REQUIRE(ttd.getDescription() == descriptor);
	}
}

TEST_CASE("test editDescription")
{
	TicTacToeBoardDescriptor ttd;

	SECTION("editDescription returns correct descriptor after editing")
	{
		int pos = 0;
		char val = 'x';

		const std::string descriptor = "x........";
		REQUIRE(ttd.editDescription(pos, val).getDescription() == descriptor);
	}
}
