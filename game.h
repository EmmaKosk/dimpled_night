#pragma once
#include "player.h"
#include "world.h"
#include "camera.h"

class Game{
public:
    Game(std::string title, int width, int height);
    void input();
    void update();
    void render();
private:
    Player* player;
    World world;
    Graphics graphics;

    // timing
    //how much time between frames
    float dt;
    Uint64 performance_frequency;
    Uint64 prev_counter;
    float lag;
    Camera camera;
};
