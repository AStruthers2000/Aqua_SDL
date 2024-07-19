#pragma once
//#include <SDL.h>
#include <memory>
#include <SDL_render.h>
#include <SDL_video.h>
#include <stack>
#include "EngineParameters.h"
//#include "GameStates/GameState.h"

namespace AquaEngine
{
    class GameState;
    class GameSubState;

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
}
