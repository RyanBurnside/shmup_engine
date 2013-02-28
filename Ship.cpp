#include "Ship.h"


// this function is used for enemies who do not need a path and move in a linear fashon
Ship::Ship(float x, float y, float speed, float direction, int width, int height, Image_Data*):
Actor(x, y, speed, direction, width, height, sprite)
{
    this->path = 0;
}

// overloaded function to include a path
Ship::Ship(float x, float y, float speed, float direction, int width, int height, Image_Data* sprite, Path* path):
Actor(x, y, speed, direction, width, height, sprite)
{

}

Ship::~Ship()
{
    //dtor
}
