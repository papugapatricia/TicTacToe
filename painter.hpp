#pragma once

#include "board.hpp"
#include "cell.hpp"

class Painter {
public:
    void DrawBoard(const Board& board);
    void WriteText(int x, int y, const char* text);
};
