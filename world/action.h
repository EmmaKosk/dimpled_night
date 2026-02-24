#pragma once

class GameObject;
class World;

enum class ActionType {
    None,
    Jump,
    MoveLeft,
    MoveRight,
};
class Action {
public:
    virtual ~Action() = default;
    virtual void perform(World& world, GameObject& obj) = 0;

};

class Jump : public Action {
    void perform(World& world, GameObject& obj);
};

class MoveRight : public Action {
    void perform(World&, GameObject &obj) override;
};
