#include "game_engine.hpp"
#include <iostream>

GameEngine::GameEngine(Player player1, Player player2)
    : _player1(player1), _player2(player2), _currentPlayer(&_player1) {}

void GameEngine::Init() {
}

void GameEngine::Run() {
    while (!CheckGameOver()) {
        Painter painter;
        painter.DrawBoard(_board);
        
        int row, col;
        std::cout << "Jucător " << (_currentPlayer == &_player1 ? "X" : "O") << ", introduceți rândul și coloana (0, 1 sau 2): ";
        std::cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && _board.GetCell(row, col) == CellState::Empty) {
            _currentPlayer->MakeMove(_board, row, col);
            SwitchPlayer();
        } else {
            std::cout << "Mutare invalidă, încercați din nou." << std::endl;
        }
    }

    Painter painter;
    painter.DrawBoard(_board);
    if (_board.CheckWin(_player1.GetSymbol())) {
        std::cout << "Jucătorul X a câștigat!" << std::endl;
    } else if (_board.CheckWin(_player2.GetSymbol())) {
        std::cout << "Jucătorul O a câștigat!" << std::endl;
    } else {
        std::cout << "Egalitate!" << std::endl;
    }
}

void GameEngine::SwitchPlayer() {
    _currentPlayer = (_currentPlayer == &_player1) ? &_player2 : &_player1;
}

bool GameEngine::CheckGameOver() const {
    return _board.IsFull() || _board.CheckWin(_player1.GetSymbol()) || _board.CheckWin(_player2.GetSymbol());
}
