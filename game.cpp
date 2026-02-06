#include "game.h"

Game::Game(std::string title, int width, int height)
    : graphics{title, width, height}, world{31, 11}, dt{1.0/60.0}, camera{graphics, 64}, lag{0.0}, performance_frequency{SDL_GetPerformanceFrequency()}, prev_counter{SDL_GetPerformanceCounter()}{

    //load the first 'level'
    //boundrey walls
    world.add_platform(0,0,30,1);
    world.add_platform(0,0,1,10);
    world.add_platform(0,10,31,1);

    //platforms
    world.add_platform(3,7,4,1);
    world.add_platform(13,4,6,1);

    player = world.create_player();
}

void Game::input() {
    player->handle_input();

    //more to be added
}

void Game::update() {
    Uint64 now = SDL_GetPerformanceCounter();
    lag += (now - prev_counter) / (float)performance_frequency;
    prev_counter = now;
    while(lag >= dt) {
        world.update(dt);
        camera.update(player->position, dt);
        lag -= dt;
    }

}

void Game::render() {
    //clear
    graphics.clear();

    //draw the world
    camera.render(world.tilemap);

    //draw the player
    auto [player_positition, color] = player->get_sprite();
    camera.render(player_positition, color);

    graphics.update();
}