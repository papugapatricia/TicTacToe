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
    GameEngine() : _currentPlayer(nullptr) {} 
    GameEngine(Player player1, Player player2);

    GameEngine(const GameEngine& other);

    GameEngine& operator=(const GameEngine& other);

    bool operator==(const GameEngine& other) const;
    friend std::istream& operator>>(std::istream& in, GameEngine& engine);
    friend std::ostream& operator<<(std::ostream& out, const GameEngine& engine);

    void Init();
    void Run();
    void SwitchPlayer();
    bool CheckGameOver() const;
};
