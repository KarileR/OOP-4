#include "../headers/timer.h"

void Timer::reset() {
    start = hrClock::now();
}