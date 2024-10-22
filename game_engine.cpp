#include "game_engine.hpp"

GameEngine::GameEngine(Player player1, Player player2)
    : _player1(player1), _player2(player2), _currentPlayer(&_player1) {}

GameEngine::GameEngine(const GameEngine& other)
    : _board(other._board), _player1(other._player1), _player2(other._player2),
      _currentPlayer(other._currentPlayer == &other._player1 ? &_player1 : &_player2) {}

GameEngine& GameEngine::operator=(const GameEngine& other) {
    if (this != &other) { 
        _board = other._board; 
        _player1 = other._player1; 
        _player2 = other._player2;
        
        _currentPlayer = (other._currentPlayer == &other._player1) ? &_player1 : &_player2;
    }
    return *this; 
}

bool GameEngine::operator==(const GameEngine& other) const {
    return _board == other._board && _player1 == other._player1 &&
           _player2 == other._player2 && _currentPlayer == other._currentPlayer;
}

std::istream& operator>>(std::istream& in, GameEngine& engine) {
    in >> engine._board >> engine._player1 >> engine._player2;
    
    int currentPlayerIndex;
    in >> currentPlayerIndex;
    engine._currentPlayer = (currentPlayerIndex == 1) ? &engine._player1 : &engine._player2;
    
    return in;
}

std::ostream& operator<<(std::ostream& out, const GameEngine& engine) {
    out << "Board:\n" << engine._board;
    out << "Player 1: " << engine._player1.GetSymbol() << "\n";
    out << "Player 2: " << engine._player2.GetSymbol() << "\n";
    out << "Current Player: " << ((engine._currentPlayer == &engine._player1) ? "Player 1" : "Player 2") << "\n";
    return out;
}

void GameEngine::Init() {
    _board = Board(); 
    _currentPlayer = &_player1; 
}

void GameEngine::Run() {
    Init();
    while (!CheckGameOver()) {
        SwitchPlayer();
    }
}
void GameEngine::SwitchPlayer() {
    _currentPlayer = (_currentPlayer == &_player1) ? &_player2 : &_player1;
}
bool GameEngine::CheckGameOver() const {
    CellState player1Symbol = (_player1.GetSymbol() == 'X') ? CellState::X : CellState::O; 
    CellState player2Symbol = (_player2.GetSymbol() == 'X') ? CellState::X : CellState::O; 
    
    return _board.CheckWin(player1Symbol) || _board.CheckWin(player2Symbol) || _board.IsFull();
}
