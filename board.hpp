#pragma once

#include "cell.hpp"
#include <iostream>

class Board {
    Cell _cells[3][3]; 
    int size; 

public:
    Board();  
    Board(int size);  
    Board(const Board& other);  

    Board& operator=(const Board& other);

    bool operator==(const Board& other) const;

    void SetCell(int row, int col, CellState state);
    CellState GetCell(int row, int col) const;

    bool IsFull() const;
    bool CheckWin(CellState state) const;

    friend std::istream& operator>>(std::istream& in, Board& board);
    friend std::ostream& operator<<(std::ostream& out, const Board& board);
};
