#include "game.hpp"

// INITIALIZING GAME INSTANCE
fr0sty::Game* fr0sty::Game::_instance = nullptr;

namespace fr0sty {
    
    void Game::run() {
        Game::init();
        _clock.start();
        
        Game::sys_print("STARTING!", true);

        while (Game::running()) {
            Game::events();
            Game::update(_dt);

            _dt = static_cast<float>(_clock.getTicks()) / 1000.0f;
            _clock.start();

            Game::render();

        }

        Game::quit();
    }

    bool Game::init() {

        // INITIALIZING SDL
        if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init( IMG_INIT_JPG | IMG_INIT_PNG ) != 0) {
            Game::sys_print("FAILED TO INITIALIZE SDL", true);
            return _running = false;
        }

        // CREATING WINDOW
        _window = SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

        if (_window == nullptr) {
            Game::sys_print("FAILED TO CREATE WINDOW!", true);
            return _running = false;
        }

        // CREATING RENDERER
        _renderer = SDL_CreateRenderer(_window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (_renderer == nullptr) {
            Game::sys_print("FAILED TO CREATE RENDERER!", true);
            return _running = false;
        }

        return _running = true;
    }

    bool Game::quit() {
        SDL_DestroyWindow(_window);
        SDL_DestroyRenderer(_renderer);

        IMG_Quit();
        SDL_Quit();

        return _running = false;
    } 

    void Game::update(float dt) {

    }

    void Game::render() {
        SDL_SetRenderDrawColor(_renderer, GAME_BG_COLOR);
        SDL_RenderClear(_renderer);

        // DRAW
        
        
        

        SDL_RenderPresent(_renderer);
    }

    void Game::events() {
        SDL_PollEvent(&_event);

        switch (_event.type) {
        case SDL_QUIT:
            _running = false;
            quit();
            break;
        case SDL_KEYDOWN:
            switch (_event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    _running = false;
                    quit();
                    break;
            }
        }
    }

} // 	 fr0sty