#include "snake_game_app.h"

SnakeGame::SnakeGame() : snake(), food() {
}

void SnakeGame::setup() {
    game_over = false;
    score = 0;
}

void SnakeGame::update() {
    //Check collisions
    if (snake.CheckWallCollision() || snake.CheckBodyCollision()) {
        game_over = true;
    }

    if (!game_over) {
        //Check if food is eaten
        if (glm::distance(snake.head.getCenter(), food.food_position) <=
            food.food_radius + (pow(pow(snake.head.getHeight(), 2) + pow(snake.head.getWidth(), 2), 0.5)) / 2) {

            snake.IncreaseSnakeSize();
            food.food_position = glm::vec2(randFloat(10, float(window_width) - 10.0f),
                                           randFloat(15, float(window_height) - 10.0f));    //new food position
            if (snake.speed < snake.max_speed) {
                snake.speed += 0.45f;               //increase snake speed.
            }
            food.color = Color(CM_HSV, Rand::randFloat(), 0.5f, 1.0f);  //new food color
            score++;
        }

        snake.MoveSnake();
    }

}
void SnakeGame::draw() {

    if (!game_over) {

        gl::clear(Color(0, 0, 0), true);
        snake.DrawSnake();

        food.DrawFood();

        //print score
        ci::gl::color(ci::Color("white"));
        auto font = ci::Font("Helvetica", 20.0);
        auto tf = ci::gl::TextureFont::create(font);
        tf->drawString("Score: " + std::to_string(score), glm::vec2(window_width - 70, 20));
    }

    if (game_over) {
        //prints score
        ci::gl::color(ci::Color("white"));
        auto font = ci::Font("Helvetica", 50.0);
        auto tf = ci::gl::TextureFont::create(font);
        tf->drawString("Game Over! \nScore: " + std::to_string(score), glm::vec2(window_width/2, window_height/2));
    }
}

void SnakeGame::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
        case ci::app::KeyEvent::KEY_RIGHT:
            if (snake.direction == 'L') break;
            snake.velocity = glm::vec2(snake.speed,0.0f);
            snake.direction = 'R';
            break;

        case ci::app::KeyEvent::KEY_LEFT:
            if (snake.direction == 'R') break;
            snake.velocity = glm::vec2(-1*snake.speed,0.0f);
            snake.direction = 'L';
            break;

        case ci::app::KeyEvent::KEY_UP:
            if (snake.direction == 'D') break;
            snake.velocity = glm::vec2(0.0f,-1*snake.speed);
            snake.direction = 'U';
            break;

        case ci::app::KeyEvent::KEY_DOWN:
            if (snake.direction == 'U') break;
            snake.velocity = glm::vec2(0.0f, snake.speed);
            snake.direction = 'D';
            break;
    }
}