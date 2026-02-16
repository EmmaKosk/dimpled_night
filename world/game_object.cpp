#include "game_object.h"
#include "world.h"
#include "physics.h"


GameObject::GameObject(const Vec<float>& position, const Vec<int>& size, World& world)
    : physics{position,{0,0}, {0, 0}}, size{size} {
    physics.acceleration.y = physics.gravity;
}

GameObject::~GameObject() {}

void GameObject::input(World &world) {
    const bool *key_states = SDL_GetKeyboardState(NULL);

    physics.acceleration.x = 0;
    physics.acceleration.y = physics.gravity;
    if (key_states[SDL_SCANCODE_A]) {
        //velocity.x += -8;
        physics.acceleration.x += -physics.walk_acceleration;
    }
    if (key_states[SDL_SCANCODE_D]) {
        //velocity.x += 8;
        physics.acceleration.x += physics.walk_acceleration;
    }
    if (key_states[SDL_SCANCODE_SPACE]) {
        physics.velocity.y = physics.jump_velocity;
    }
}

void GameObject::update(World &world, double dt) {

}

std::pair<Vec<float>, Color> GameObject::get_sprite() const {
    return {physics.position, {255, 0, 255, 255}};
}
