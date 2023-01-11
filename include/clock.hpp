#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <SDL/SDL.h>

namespace fr0sty {
    
    /// @brief A structure for handling and updating tick time and game time
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
}
#endif // !CLOCK_HPP