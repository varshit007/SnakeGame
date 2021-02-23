#include "Food.h"

/**
 * This constructor initializes the food's
 * position, radius and color.
 */
Food::Food() {
    food_position = glm::vec2(window_width/2, window_height/2);
    food_radius = 8.0;
    color = Color("yellow");
}

/**
 * This method draws the food.
 */
void Food::DrawFood() {
    ci::gl::color(color);
    gl::drawSolidCircle(food_position,food_radius);
}
