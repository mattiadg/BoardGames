#ifndef GAMES_TICTACTOEBOARDDESCRIPTOR_H
#define GAMES_TICTACTOEBOARDDESCRIPTOR_H

#include <string>

const int BOARD_SIZE = 9;

class TicTacToeBoardDescriptor {
public:
    TicTacToeBoardDescriptor() : TicTacToeBoardDescriptor(".........") {};
    TicTacToeBoardDescriptor(const std::string d);
    std::string getDescription() const { return descriptor;}
    const TicTacToeBoardDescriptor editDescription(int pos, char val) const;
    const char& operator[] (int i) const { return descriptor[i];}

private:
    const std::string descriptor;
};

#endif //GAMES_TICTACTOEBOARDDESCRIPTOR_H
