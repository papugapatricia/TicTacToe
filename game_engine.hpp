#pragma once

#include "board.hpp"
#include "player.hpp"
#include <iostream>

class GameEngine {
    Board _board;
    Player _player1;
    Player _player2;
    Player* _currentPlayer;

public:
    // Constructori
    GameEngine() : _currentPlayer(nullptr) {} // Constructor implicit
    GameEngine(Player player1, Player player2);

    // Constructor de copiere
    GameEngine(const GameEngine& other);

    // Operator de atribuire
    GameEngine& operator=(const GameEngine& other);

    // Operator de comparație
    bool operator==(const GameEngine& other) const;

    // Suprascriere operatori de citire și afișare
    friend std::istream& operator>>(std::istream& in, GameEngine& engine);
    friend std::ostream& operator<<(std::ostream& out, const GameEngine& engine);

    void Init();
    void Run();
    void SwitchPlayer();
    bool CheckGameOver() const;
};
