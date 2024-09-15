#pragma once

#include "cell.hpp"

class Board {
    Cell _cells[3][3]; // Tabla de joc TicTacToe 3x3
public:
    Board();
    void SetCell(int row, int col, CellState state);
    CellState GetCell(int row, int col) const;
    bool IsFull() const;
    bool CheckWin(CellState state) const;
};
