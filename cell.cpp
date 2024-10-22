#include "cell.hpp"

Cell::Cell(int r, int c, CellState s) : row(r), col(c), state(s) {}

Cell::Cell(const Cell& other) : row(other.row), col(other.col), state(other.state) {}

Cell& Cell::operator=(const Cell& other) {
    if (this != &other) {
        row = other.row;
        col = other.col;
        state = other.state;
    }
    return *this;
}

bool Cell::operator==(const Cell& other) const {
    return row == other.row && col == other.col && state == other.state;
}

CellState Cell::GetState() const { return state; }

void Cell::SetState(CellState s) { state = s; }

std::istream& operator>>(std::istream& in, Cell& cell) {
    int r, c, s;
    in >> r >> c >> s;
    cell = Cell(r, c, static_cast<CellState>(s));
    return in;
}

std::ostream& operator<<(std::ostream& out, const Cell& cell) {
    out << "Row: " << cell.row << ", Col: " << cell.col << ", State: " << static_cast<int>(cell.state);
    return out;
}
