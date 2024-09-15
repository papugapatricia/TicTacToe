#pragma once

#include "board.hpp"
#include "player.hpp"

class GameEngine {
    Board _board;
    Player _player1;
    Player _player2;
    Player* _currentPlayer;
public:
    GameEngine(Player player1, Player player2);
    void Init();
    void Run();
    void SwitchPlayer();
    bool CheckGameOver() const;
};
