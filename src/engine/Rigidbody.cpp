//
// Created by xCocoDev on 2019-01-22.
//

#include "Rigidbody.h"

using namespace en;

void Rigidbody::initializeMetatable(LuaState& lua) {

    lua::addProperty(lua, "velocity",    lua::property(&Rigidbody::velocity));
    lua::addProperty(lua, "isKinematic", lua::property(&Rigidbody::isKinematic));
    lua::addProperty(lua, "useGravity",  lua::property(&Rigidbody::useGravity));
    lua::addProperty(lua, "bounciness",  lua::property(&Rigidbody::bounciness));
    lua::addProperty(lua, "radius",      lua::property(&Rigidbody::radius));
}
