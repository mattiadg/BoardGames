#ifndef GAMES_CONNECTXBOARD_H
#define GAMES_CONNECTXBOARD_H

#include <string>
#include <iostream>

/*
 * Represents a board in a given position
 */
typedef enum {
    Continue, Win1, Win2, Draw
} GameState;

const int BOARD_SIZE = 4;

typedef std::string descriptor;
typedef struct {
    int col;
    char symbol;
} ConnectxMove;

class ConnectXBoard {
public:
    ConnectXBoard() :d(descriptor (16, '.')) {}
    ConnectXBoard(const descriptor & descr) :d(descr) {}
    ConnectXBoard(const ConnectXBoard& otherBoard) = default;
    ConnectXBoard(ConnectXBoard&& otherBoard) = default;
    int numOccupied() const;
    GameState getGameState() const;

    ConnectXBoard makeMove(ConnectxMove col);
    const descriptor & getDescriptor() const { return d;}
    bool isLegal(ConnectxMove col) const;
    //const char& operator[] (int i) const { return d[i];}
    //const char& operator[] (int i) { return d[i];}

    static constexpr char symbols[2] = {'R', 'U'};
private:
    const descriptor d;
    int checkRow(int row) const ;
    int checkCol(int col) const ;
    int checkDiagonals() const ;
    int checkLine(int start, int increment, int topend) const;
    int findFirstFreePositionInCol(int c) const;
    GameState scoreToGameState(int) const;
};

std::ostream& operator<< (std::ostream&, const ConnectXBoard&);

#endif //GAMES_CONNECTXBOARD_H
