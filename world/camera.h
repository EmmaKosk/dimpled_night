#pragma once

#include "tilemap.h"
#include <vec.h>
#include "toggle.h"

class Graphics;
class Color;

class Camera {
public:
    Camera(Graphics& graphics, float tilesize);

    void handle_input();
    void update(const Vec<float>& new_location, float dt);
    Vec<float> world_to_screen(const Vec<float>& world_posistion) const;

    void render(const Vec<float>& position, const Color& color, bool filled=true) const;
    void render(const Tilemap& tilemap) const;

    void set_location(const Vec<float>& new_location);


private:
    Graphics& graphics;
    float tilesize;
    Vec<float> location;
    Toggle grid_toggle;

    void calculate_visable_tiles();
    Vec<int> visable_min, visable_max;
    Vec<float> goal, velocity, acceleration;
};
