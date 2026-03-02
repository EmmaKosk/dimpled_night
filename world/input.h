#pragma once
#include "action.h"
#include "SDL3/SDL.h"

class GameObject;

class Input {
public:
    virtual ~Input() = default;

    virtual void collect_discrete_events(SDL_Event* event);
    virtual void get_input() = 0;
    virtual void handle_input(World& world, GameObject& obj);

    ActionType next_action_type = ActionType::None;
};
