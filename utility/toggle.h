#pragma once
#include<SDL3/SDL.h>

class Toggle {
public:
    Toggle(bool on=false, double required_time=.25);
    void flip();

    bool on;

private:
    double required_time;
    double elasped;
    Uint64 performance_frequency;
    Uint64 prev_counter;
};
