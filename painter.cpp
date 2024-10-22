#include "player.hpp"

Player::Player(CellState symbol) : _symbol(symbol) {}

Player::Player(const Player& other) : _symbol(other._symbol) {}

Player& Player::operator=(const Player& other) {
    if (this != &other) { 
        _symbol = other._symbol;
    }
    return *this; 
}
bool Player::operator==(const Player& other) const {
    return _symbol == other._symbol;
}
