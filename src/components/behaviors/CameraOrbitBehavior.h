//
// Created by xCocoDev on 16/12/18.
//

#ifndef SAXION_Y2Q2_RENDERING_CAMERAORBITBEHAVIOUR_H
#define SAXION_Y2Q2_RENDERING_CAMERAORBITBEHAVIOUR_H

#include <SFML/Window.hpp>
#include "Behavior.h"
#include "Actor.h"
#include "glm.hpp"
#include "ComponentsToLua.h"

class CameraOrbitBehavior : public en::Behavior {

    LUA_TYPE(CameraOrbitBehavior)

public:

    static CameraOrbitBehavior& addFromLua(en::Actor& actor, en::LuaState& lua);

    explicit CameraOrbitBehavior(en::Actor actor, float distance = 10.f, float minTilt = -45.f, float maxTilt = 45.f, float rotationSpeed = 0.1f);
    void update(float dt) override;

    void setTarget(const en::Actor& target);

private:

    sf::Vector2i updateMouseInput();

    en::Actor m_target;

    float m_distance;
    float m_minTilt;
    float m_maxTilt;
    float m_rotationSpeed;

    sf::Vector2i m_previousMousePosition;
};


#endif //SAXION_Y2Q2_RENDERING_CAMERAORBITBEHAVIOUR_H
