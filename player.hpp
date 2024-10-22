#include "board.hpp"

class Player {
    CellState _symbol; 
public:
    Player() : _symbol(CellState::Empty) {}

    Player(CellState symbol) : _symbol(symbol) {}

    Player(const Player& other) : _symbol(other._symbol) {}

    Player& operator=(const Player& other) {
        if (this != &other) {
            _symbol = other._symbol;
        }
        return *this;
    }

    char GetSymbol() const {
        switch (_symbol) {
            case CellState::X:
                return 'X';
            case CellState::O:
                return 'O';
            case CellState::Empty:
                return ' ';
            default:
                return ' '; 
        }
    }

    bool operator==(const Player& other) const {
        return _symbol == other._symbol; 
    }

    friend std::istream& operator>>(std::istream& in, Player& player) {
        char symbol;
        in >> symbol;
        if (symbol == 'X') {
            player._symbol = CellState::X;
        } else if (symbol == 'O') {
            player._symbol = CellState::O;
        } else {
            player._symbol = CellState::Empty; 
        }
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& player) {
        out << player.GetSymbol();
        return out;
    }
};
