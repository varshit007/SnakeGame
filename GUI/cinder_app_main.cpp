
#include "snake_game_app.h"

//Set window size to 600 X 600
void prepareSettings( SnakeGame::Settings *settings ) {
    settings->setWindowSize( 600, 600 );
    settings->setFrameRate( 20.0f );
}

//Entry point
CINDER_APP( SnakeGame, RendererGl, prepareSettings );

