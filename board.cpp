#include "board.hpp"

Board::Board() : size(3) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            _cells[i][j] = {i, j, CellState::Empty};
        }
    }
}

Board::Board(int size) : size(size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            _cells[i][j] = {i, j, CellState::Empty};
        }
    }
}

Board::Board(const Board& other) : size(other.size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            _cells[i][j] = other._cells[i][j];
        }
    }
}

Board& Board::operator=(const Board& other) {
    if (this != &other) {
        size = other.size;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                _cells[i][j] = other._cells[i][j];
            }
        }
    }
    return *this;
}

bool Board::operator==(const Board& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (!(_cells[i][j] == other._cells[i][j])) {
                return false;
            }
        }
    }
    return true;
}

void Board::SetCell(int row, int col, CellState state) {
    _cells[row][col].SetState(state);
}

CellState Board::GetCell(int row, int col) const {
    return _cells[row][col].GetState();
}

bool Board::IsFull() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (_cells[i][j].GetState() == CellState::Empty) {
                return false;
            }
        }
    }
    return true;
}

bool Board::CheckWin(CellState state) const {
    for (int i = 0; i < size; ++i) {
        if (std::all_of(_cells[i], _cells[i] + size, [state](const Cell& cell) { return cell.GetState() == state; })) {
            return true;
        }
    for (int j = 0; j < size; ++j) {
        bool win = true;
        for (int i = 0; i < size; ++i) {
            if (_cells[i][j].GetState() != state) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }
    bool diagonalWin1 = true, diagonalWin2 = true;
    for (int i = 0; i < size; ++i) {
        if (_cells[i][i].GetState() != state) diagonalWin1 = false;
        if (_cells[i][size - 1 - i].GetState() != state) diagonalWin2 = false;
    }
    return diagonalWin1 || diagonalWin2;
}
std::istream& operator>>(std::istream& in, Board& board) {
    for (int i = 0; i < board.size; ++i) {
        for (int j = 0; j < board.size; ++j) {
            CellState state;
            in >> state;
            board.SetCell(i, j, state);
        }
    }
    return in;
}
std::ostream& operator<<(std::ostream& out, const Board& board) {
    for (int i = 0; i < board.size; ++i) {
        for (int j = 0; j < board.size; ++j) {
            CellState state = board.GetCell(i, j);
            char symbol;
            switch (state) {
                case CellState::X:
                    symbol = 'X';
                    break;
                case CellState::O:
                    symbol = 'O';
                    break;
                case CellState::Empty:
                default:
                    symbol = '.';
                    break;
            }
            out << symbol << " ";
        }
        out << std::endl;
    }
    return out;
}
