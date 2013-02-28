#include "Actor.h"
#include <math.h>

Actor::Actor(float x, float y, float speed, float direction, int width, int height, Image_Data* sprite = 0)
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->direction = direction;
    this->width = width;
    this->height = height;
    this->sprite = sprite;
    // these are never to be set manually by the programmer
    this->x_step = cos(direction) * speed;
    this->y_step = sin(direction) * speed;

    //ctor
}

float Actor::get_direction()
{
    return direction;
}


void Actor::set_direction(float dir)
{
    direction = dir;
    x_step = cos(direction) * speed;
    y_step = sin(direction) * speed;
}

float Actor::get_speed()
{
        return speed;
}

void Actor::set_speed(float new_speed)
{
    x_step = cos(direction) * new_speed;
    y_step = sin(direction) * new_speed;
}

void Actor::move()
{
    if(speed != 0)
    {
        x += x_step;
        y += y_step;
    }
}

Actor::~Actor()
{
    //dtor
}
