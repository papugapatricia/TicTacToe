#pragma once

#include "cell.hpp"
#include <iostream>

class Board {
    Cell _cells[3][3]; // Tabla de joc TicTacToe 3x3
    int size;  // Dimensiunea tablei de joc (3x3 implicit)

public:
    // Constructori
    Board();  // Constructor implicit
    Board(int size);  // Constructor cu parametri
    Board(const Board& other);  // Constructor de copiere

    // Operator de atribuire
    Board& operator=(const Board& other);

    // Operator de egalitate
    bool operator==(const Board& other) const;

    // Setteri și getteri pentru celule
    void SetCell(int row, int col, CellState state);
    CellState GetCell(int row, int col) const;

    // Verificare stare joc
    bool IsFull() const;
    bool CheckWin(CellState state) const;

    // Operatorii de intrare/ieșire
    friend std::istream& operator>>(std::istream& in, Board& board);
    friend std::ostream& operator<<(std::ostream& out, const Board& board);
};
