#include "game_object.h"
#include "world.h"
#include "physics.h"
#include "fsm.h"
#include "action.h"

GameObject::GameObject(const Vec<float>& position, const Vec<int>& size, World& world, FSM* fsm, Color color)
    : physics{position,{0,0}, {0, 0}}, size{size}, fsm{fsm}, color{color} {
    physics.acceleration.y = physics.gravity;
    fsm->current_state->on_enter(world, *this);
}

GameObject::~GameObject() {
    delete fsm;
}

void GameObject::input(World &world) {
    const bool *key_states = SDL_GetKeyboardState(NULL);
    ActionType actiontype = ActionType::None;

    if (key_states[SDL_SCANCODE_A]) {
        actiontype = ActionType::MoveLeft;
    }
    else if (key_states[SDL_SCANCODE_D]) {
        actiontype = ActionType::MoveRight;
    }
    else if (key_states[SDL_SCANCODE_SPACE]) {
        actiontype = ActionType::Jump;
    }
    Action* action = fsm->current_state->input(world, *this, actiontype);
    if(action != nullptr) {
        action->perform(world, *this);
    }
}

void GameObject::update(World &world, double dt) {
    fsm->current_state->update(world, *this, dt);
}

std::pair<Vec<float>, Color> GameObject::get_sprite() const {
    return {physics.position, color};
}
