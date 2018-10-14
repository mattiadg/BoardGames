#include <iostream>
#include "ConnectXBoard.h"

int main () {
    ConnectXBoard board;
    std::cout << board.getDescriptor() << std::endl;
    std::cout << board;
    ConnectXBoard board1("R...RU..RU..RUU.");
    std::cout << board1;
    std::cout << board1.getGameState() << std::endl;
}