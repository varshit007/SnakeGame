#include "Snake.h"

/**
 * This is a default constructor.
 * It initializes the snake's head position and speed.
 */
Snake::Snake() {
    head = Rectf(glm::vec2(1.0f,1.0f), glm::vec2(10.0f,10.0f));
    snake_body.push_back(head);
    speed = 7.0f;
    max_speed = 15.0f;
}

Snake::Snake(Rectf & head_) {
    head = head_;
    snake_body.push_back(head);
    speed = 7.0f;
    max_speed = 15.0f;
}

/**
 * Updates the head's position based on the velocity.
 * Also updates the position of the body parts.
 */
void Snake::MoveSnake() {

    glm::vec2 up_left = head.getUpperLeft() + velocity;
    glm::vec2 bot_right = head.getLowerRight() + velocity;
    Rectf temp1 = head;
    head = Rectf(up_left, bot_right);

    for (int i = snake_body.size() - 2; i >= 0; i-- ) {
        Rectf temp2 = snake_body.at(i);
        snake_body.at(i) = temp1;
        temp1 = temp2;
    }
}

/**
 * Every time food is eaten, this method is called and it
 * creates a new head and pushes it into the snakes body,
 * effectively adding a new body part.
 */
void Snake::IncreaseSnakeSize() {
    Rectf new_head;
    switch (direction) {
        case 'R':
            new_head = Rectf(head.getX1()+head.getWidth(), head.getY1(), head.getX2()+head.getWidth(), head.getY2());
            snake_body.push_back(new_head);
            head = new_head;
            break;

        case 'L':
            new_head = Rectf(head.getX1()-head.getWidth(), head.getY1(), head.getX2()-head.getWidth(), head.getY2());
            snake_body.push_back(new_head);
            head = new_head;
            break;

        case 'U':
            new_head = Rectf(head.getX1(), head.getY1()-head.getHeight(), head.getX2(), head.getY2()-head.getHeight());
            snake_body.push_back(new_head);
            head = new_head;
            break;

        case 'D':
            new_head = Rectf(head.getX1(), head.getY1()+head.getHeight(), head.getX2(), head.getY2()+head.getHeight());
            snake_body.push_back(new_head);
            head = new_head;
            break;
    }
}

/**
 * Draw all the rectangles which are part of the snakes body
 * including the head.
 */
void Snake::DrawSnake() {
    for (int i = snake_body.size() - 1; i >= 0; i-- ) {
        if (i == snake_body.size() - 1) {
            ci::gl::color(ci::Color("red"));
            gl::drawSolidRect(head);
            continue;
        }

        ci::gl::color(ci::Color("green"));
        gl::drawSolidRect(snake_body.at(i));
    }
}

/**
 * Checks collision with all the 4 walls
 * @return a boolean which tells if a collision occurred or not.
 */
bool Snake::CheckWallCollision() {
    //Left wall
    if(head.x1 <= 0.0f) {
        return true;
    }
    //Right wall
    if(head.x2 >= float(window_width)) {
        return true;
    }
    //Top wall
    if(head.y1 <= 0.0f) {
        return true;
    }
    //Bottom wall
    if(head.y2 >= float(window_height)) {
        return true;
    }
    return false;
}

/**
 * Checks collision with the snake's body itself.
 * @return a boolean which tells if a collision occurred or not.
 */
bool Snake::CheckBodyCollision() {
    for (size_t i = 0; i < snake_body.size() - 1; i++) {
        if (head.x1 == snake_body.at(i).x1 &&  head.y1 == snake_body.at(i).y1) {
            return true;
        }
    }
    return false;
}
