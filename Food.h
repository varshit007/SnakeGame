#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Color.h"

using namespace ci;
using namespace ci::app;

class Food {
public:
    Food();
    void DrawFood();

    Color color;
    float food_radius;
    glm::vec2 food_position;
    int window_width = ci::app::getWindowWidth();
    int window_height = ci::app::getWindowHeight();
};