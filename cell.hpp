#pragma once

enum class CellState {
    Empty,
    X,
    O
};

struct Cell {
    int row;
    int col;
    CellState state;
};
