#include "painter.hpp"
#include <iostream>

void Painter::DrawBoard(const Board& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char symbol;
            switch (board.GetCell(i, j)) {
                case CellState::X: symbol = 'X'; break;
                case CellState::O: symbol = 'O'; break;
                default: symbol = '.'; break; 
            }
            std::cout << symbol << ' ';
        }
        std::cout << std::endl;
    }
}
