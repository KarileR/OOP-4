#ifndef timer_h
#define timer_h

#include <chrono>

class Timer 
{
    private:
        using hrClock = std::chrono::high_resolution_clock;
        using durationDouble = std::chrono::duration<double>;
        std::chrono::time_point<hrClock> start;
    public:
        Timer() : start{ hrClock::now() } {}
        void reset();
        double elapsed() const {
            return durationDouble (hrClock::now() - start).count();
        }
};
#endif