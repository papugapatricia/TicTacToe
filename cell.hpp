#pragma once

#include <iostream>

enum class CellState {
    Empty,
    X,
    O
};


std::istream& operator>>(std::istream& in, CellState& state) {
    char input;
    in >> input;

    switch (input) {
        case 'X':
        case 'x':
            state = CellState::X;
            break;
        case 'O':
        case 'o':
            state = CellState::O;
            break;
        case ' ':
            state = CellState::Empty;
            break;
        default:
            in.setstate(std::ios::failbit); 
            break;
    }
    return in; }



struct Cell {
    int row;
    int col;
    CellState state;

    Cell(int r = 0, int c = 0, CellState s = CellState::Empty);
    Cell(const Cell& other);

    Cell& operator=(const Cell& other);

    bool operator==(const Cell& other) const;

    CellState GetState() const;  // Getter pentru state
    void SetState(CellState s);  // Setter pentru state

    friend std::istream& operator>>(std::istream& in, Cell& cell);
    friend std::ostream& operator<<(std::ostream& out, const Cell& cell);
};
