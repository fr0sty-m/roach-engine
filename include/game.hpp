#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "SETTINGS.hpp"

namespace fr0sty {

    enum class STATE { PLAY, SPLASH, MENU };

    struct Clock {
        private:
            int _startTime;
            int _pausedTime;
            bool _started;
            bool _paused;

        public:
            Clock()
                : _startTime(0), _pausedTime(0), _started(false), _paused(false) {}

            void start() {
                _started = true;
                _paused = false;

                _startTime = SDL_GetTicks();
                _pausedTime = 0;
            }

            void stop() {
                _started = false;
                _paused = false;

                _startTime = 0;
                _pausedTime = 0;
            }

            void pause() {
                if (_started && !_paused) {
                    _paused = true;

                    _pausedTime = SDL_GetTicks() - _startTime;
                    _startTime = 0;
                }
            }

            void resume() {
                if (_started && _paused) {
                    _paused = false;

                    _startTime = SDL_GetTicks() - _pausedTime;
                    _pausedTime = 0;
                }
            }

            int getTicks() {
                if (_started) {
                    return _paused ? _pausedTime : SDL_GetTicks() - _startTime;
                }
                return 0;
            }
        
    };


    class Game {
        private:
            Game() = default;

            static Game* _instance;

            bool _running;       

            SDL_Window* _window;
            SDL_Renderer* _renderer;
            SDL_Surface* _surface;

            Clock _clock;
            float _dt;
            STATE _state;

            SDL_Event _event;


        public:
            void sys_print(const char* msg, bool endl) {if (endl) {std::cout << "ROACH: " << msg << std::endl;} else {std::cout << msg;}}
            void sys_print(int msg, bool endl) {if (endl) {std::cout << "ROACH: " << msg << std::endl;} else {std::cout << msg;}}
            void sys_print(float msg, bool endl) {if (endl) {std::cout << "ROACH: " << msg << std::endl;} else {std::cout << msg;}}
            void sys_print(uint32_t msg, bool endl) {if (endl) {std::cout << "ROACH: " << msg << std::endl;} else {std::cout << msg;}}

            static Game* getInstance() { return _instance = (_instance != nullptr) ? _instance : new Game(); }

            inline bool running() { return _running; }

            void run();

            bool init();
            bool quit();

            void update(float dt);
            void render();
            void events();

            float getDT() { return _dt; }
        
        };	// fr0sty
}	// fr0sty
#endif // GAME_HPP