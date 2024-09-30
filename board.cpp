#include "board.hpp"

Board::Board() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            _cells[i][j] = {i, j, CellState::Empty};
        }
    }
}

void Board::SetCell(int row, int col, CellState state) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        _cells[row][col].state = state;
    }
}

CellState Board::GetCell(int row, int col) const {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        return _cells[row][col].state;
    }
    return CellState::Empty; 
}

bool Board::IsFull() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (_cells[i][j].state == CellState::Empty) {
                return false;
            }
        }
    }
    return true;
}

bool Board::CheckWin(CellState state) const {
    for (int i = 0; i < 3; ++i) {
        if (_cells[i][0].state == state && _cells[i][1].state == state && _cells[i][2].state == state) {
            return true;
             }
    }

    for (int j = 0; j < 3; ++j) {
        if (_cells[0][j].state == state && _cells[1][j].state == state && _cells[2][j].state == state) {
            return true;
        }
    }
    
    if (_cells[0][0].state == state && _cells[1][1].state == state && _cells[2][2].state == state) {
        return true;
    }
    if (_cells[0][2].state == state && _cells[1][1].state == state && _cells[2][0].state == state) {
        return true;
    }
    return false;
}
