#include "player.hpp"

// Constructor implicit
Player::Player(CellState symbol) : _symbol(symbol) {}

// Constructor de copiere
Player::Player(const Player& other) : _symbol(other._symbol) {}

Player& Player::operator=(const Player& other) {
    if (this != &other) { // Check for self-assignment
        _symbol = other._symbol;
    }
    return *this; // Return a reference to the current object
}


// Operator de egalitate
bool Player::operator==(const Player& other) const {
    return _symbol == other._symbol;
}
