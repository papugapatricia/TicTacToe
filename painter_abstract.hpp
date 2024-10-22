#pragma once

#include "board.hpp"
#include "cell.hpp"

class AbstractPainter {
public:
    virtual void DrawBoard(const Board& board) = 0; // Funcție virtuală pură
    virtual void WriteText(int x, int y, const char* text) = 0; // Funcție virtuală pură
    virtual ~AbstractPainter() {} // Destructor virtual
};


