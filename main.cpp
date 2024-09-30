#include <iostream>
#include "game_engine.hpp"
#include "player.hpp"
#include "painter.hpp"

int main() {
    Player player1(CellState::X);
    Player player2(CellState::O);
    
    GameEngine gameEngine(player1, player2);
    gameEngine.Init();

    gameEngine.Run();

    return 0;
}
