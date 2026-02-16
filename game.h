#pragma once
#include "world.h"
#include "camera.h"
#include "game_object.h"
#include "graphics.h"

class Game {
public:
    Game(std::string title, int width, int height);
    void input();
    void update();
    void render();

private:
    Graphics graphics;
    GameObject* player;
    World world;
    Camera camera;

    // timing
    float dt;
    Uint64 performance_frequency;
    Uint64 prev_counter;
    float lag;
};