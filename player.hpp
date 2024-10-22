#include "board.hpp"

class Player {
    CellState _symbol; // Member variable to hold the player's symbol
public:
    // Constructor implicit
    Player() : _symbol(CellState::Empty) {}

    // Constructor cu parametri
    Player(CellState symbol) : _symbol(symbol) {}

    // Constructor de copiere
    Player(const Player& other) : _symbol(other._symbol) {}

    // Operator de atribuire
    Player& operator=(const Player& other) {
        if (this != &other) {
            _symbol = other._symbol;
        }
        return *this;
    }

    // Getter for the symbol
    char GetSymbol() const {
        switch (_symbol) {
            case CellState::X:
                return 'X';
            case CellState::O:
                return 'O';
            case CellState::Empty:
                return ' ';
            default:
                return ' '; // Handle error
        }
    }

    // Operator de comparație
    bool operator==(const Player& other) const {
        return _symbol == other._symbol; 
    }

    // Input operator
    friend std::istream& operator>>(std::istream& in, Player& player) {
        char symbol;
        in >> symbol;
        if (symbol == 'X') {
            player._symbol = CellState::X;
        } else if (symbol == 'O') {
            player._symbol = CellState::O;
        } else {
            player._symbol = CellState::Empty; // Handle invalid input if necessary
        }
        return in;
    }

    // Output operator (optional)
    friend std::ostream& operator<<(std::ostream& out, const Player& player) {
        out << player.GetSymbol();
        return out;
    }
};
