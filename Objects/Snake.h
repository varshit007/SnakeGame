#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Color.h"
#include <vector>

using std::vector;
using namespace ci;
using namespace ci::app;

class Snake {
public:
    Snake();
    Snake(Rectf & head);
    void MoveSnake();
    void IncreaseSnakeSize();
    void DrawSnake();
    bool CheckWallCollision();
    bool CheckBodyCollision();

    float max_speed;
    Rectf head;
    vector<Rectf> snake_body;
    char direction;
    glm::vec2 velocity;
    float speed;
    int window_width = ci::app::getWindowWidth();
    int window_height = ci::app::getWindowHeight();
};
