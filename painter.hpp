#pragma once

#include "board.hpp"
#include "cell.hpp"
#include "painter_abstract.hpp"

class Painter : public AbstractPainter {
public:
    void DrawBoard(const Board& board) override; 
    void WriteText(int x, int y, const char* text) override; 
};

