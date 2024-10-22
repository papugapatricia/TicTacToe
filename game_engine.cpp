#include "game_engine.hpp"

// Constructor parametrizat
GameEngine::GameEngine(Player player1, Player player2)
    : _player1(player1), _player2(player2), _currentPlayer(&_player1) {}

// Constructor de copiere
GameEngine::GameEngine(const GameEngine& other)
    : _board(other._board), _player1(other._player1), _player2(other._player2),
      _currentPlayer(other._currentPlayer == &other._player1 ? &_player1 : &_player2) {}

GameEngine& GameEngine::operator=(const GameEngine& other) {
    if (this != &other) { // Self-assignment check
        _board = other._board; // Copy the board state
        _player1 = other._player1; // Copy player 1
        _player2 = other._player2; // Copy player 2
        
        // Update current player pointer
        _currentPlayer = (other._currentPlayer == &other._player1) ? &_player1 : &_player2;
    }
    return *this; // Return the current object
}

// Operator de comparație
bool GameEngine::operator==(const GameEngine& other) const {
    return _board == other._board && _player1 == other._player1 &&
           _player2 == other._player2 && _currentPlayer == other._currentPlayer;
}

// Operator de citire
std::istream& operator>>(std::istream& in, GameEngine& engine) {
    in >> engine._board >> engine._player1 >> engine._player2;
    
    int currentPlayerIndex;
    in >> currentPlayerIndex;
    engine._currentPlayer = (currentPlayerIndex == 1) ? &engine._player1 : &engine._player2;
    
    return in;
}

// Operator de afișare
std::ostream& operator<<(std::ostream& out, const GameEngine& engine) {
    out << "Board:\n" << engine._board;
    out << "Player 1: " << engine._player1.GetSymbol() << "\n";
    out << "Player 2: " << engine._player2.GetSymbol() << "\n";
    out << "Current Player: " << ((engine._currentPlayer == &engine._player1) ? "Player 1" : "Player 2") << "\n";
    return out;
}

// Inițializare joc
void GameEngine::Init() {
    _board = Board(); // Initializează tabla de joc
    _currentPlayer = &_player1; // Începem cu jucătorul 1
}

// Rularea jocului
void GameEngine::Run() {
    Init();
    while (!CheckGameOver()) {
        // Cod pentru a rula turul jocului, inclusiv obținerea mutării de la jucător
        // Exemplu: _currentPlayer->MakeMove(_board, row, col);
        SwitchPlayer();
    }
}

// Schimbă jucătorul curent
void GameEngine::SwitchPlayer() {
    _currentPlayer = (_currentPlayer == &_player1) ? &_player2 : &_player1;
}

// Verifică dacă jocul s-a terminat
bool GameEngine::CheckGameOver() const {
    // Convert player symbols to CellState
    CellState player1Symbol = (_player1.GetSymbol() == 'X') ? CellState::X : CellState::O; // Adjust based on your CellState definition
    CellState player2Symbol = (_player2.GetSymbol() == 'X') ? CellState::X : CellState::O; // Adjust based on your CellState definition
    
    return _board.CheckWin(player1Symbol) || _board.CheckWin(player2Symbol) || _board.IsFull();
}
