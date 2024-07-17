#pragma once

//#include <memory>
//#include <stack>
#include <SDL.h>
import std;
#include "EngineParameters.h"
#include "GameStates/GameState.h"

class GameState;

class Game
{
public:
    Game(float fps = FPS);
    ~Game();

    bool IsRunning() const { return is_running; }
    void Run();
    void PushGameState(std::unique_ptr<GameState> state);
    void PopGameState();
    void ChangeState(std::unique_ptr<GameState> state);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool is_running;
    float target_fps;
    std::stack<std::unique_ptr<GameState>> game_states;

    void HandleEvents();
    void Update(float delta_time);
    void Render();
};
