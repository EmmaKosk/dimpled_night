#pragma once
#include "fsm.h"
#include "world.h"

class Standing: public State {
public:
    void on_enter(World &, GameObject &obj) override;
    Action *input(World &, GameObject &, ActionType) override;
};

class InAir: public State {
public:
    void on_enter(World &, GameObject &) override;
    void update(World &, GameObject &, double dt) override;

    //one secound
    const double cooldown = 1;
    double elapsed = 0.0001;
};

class Running : public State {
    void on_enter(World &, GameObject &) override;
    Action *input(World &, GameObject &, ActionType) override;
};
