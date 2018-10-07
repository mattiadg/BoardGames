#include <string>
#include <stdexcept>
#include "TicTacToeBoardDescriptor.h"

TicTacToeBoardDescriptor::TicTacToeBoardDescriptor(const std::string d) :descriptor(d){
    if (d.size() != BOARD_SIZE)
        throw std::invalid_argument("Length of descriptor " + d + " is invalid!");

    for (auto c: d){
        if (c != '.' && c != 'o' && c != 'x')
            throw std::invalid_argument("Found invalid character in descriptor!");
    }
}

const TicTacToeBoardDescriptor TicTacToeBoardDescriptor::editDescription(int pos, char val) const {
    std::string newDescription(descriptor);
    newDescription[pos] = val;
    return TicTacToeBoardDescriptor(newDescription);
}