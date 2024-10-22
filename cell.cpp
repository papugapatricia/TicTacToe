#include "cell.hpp"

// Constructor cu parametri
Cell::Cell(int r, int c, CellState s) : row(r), col(c), state(s) {}

// Constructor de copiere
Cell::Cell(const Cell& other) : row(other.row), col(other.col), state(other.state) {}

// Operator de atribuire
Cell& Cell::operator=(const Cell& other) {
    if (this != &other) {
        row = other.row;
        col = other.col;
        state = other.state;
    }
    return *this;
}

// Operator de egalitate
bool Cell::operator==(const Cell& other) const {
    return row == other.row && col == other.col && state == other.state;
}

// GetState
CellState Cell::GetState() const { return state; }

// SetState
void Cell::SetState(CellState s) { state = s; }

// Operator de intrare
std::istream& operator>>(std::istream& in, Cell& cell) {
    int r, c, s;
    in >> r >> c >> s;
    cell = Cell(r, c, static_cast<CellState>(s));
    return in;
}

// Operator de ieșire
std::ostream& operator<<(std::ostream& out, const Cell& cell) {
    out << "Row: " << cell.row << ", Col: " << cell.col << ", State: " << static_cast<int>(cell.state);
    return out;
}
