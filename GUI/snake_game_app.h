#pragma once
#include "Snake.h"
#include "Food.h"

class SnakeGame : public App {
public:
    Snake snake;
    Food food;

    int window_width = ci::app::getWindowWidth();
    int window_height = ci::app::getWindowHeight();

    int score;
    bool game_over;

    SnakeGame();
    void setup() override;
    void update() override;
    void draw() override;
    void keyDown(ci::app::KeyEvent event) override;
};
