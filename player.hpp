#pragma once

#include "cell.hpp"
#include "board.hpp" // Includeți fișierul board.hpp

class Player {
    CellState _symbol;
public:
    Player(CellState symbol);
    CellState GetSymbol() const;
    void MakeMove(Board & board, int row, int col);
};
