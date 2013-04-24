#include "Actor.h"
#include <cmath>

Actor::Actor(float x, float y, float speed, float direction, int width, 
	     int height, Image_Data* sprite, int frame)
{
  this->x = x;
  this->y = y;
  this->speed = speed;
  this->direction = direction;
  this->width = width;
  this->height = height;
  this->sprite = sprite;
  this->frame = frame;

  // These are never to be set manually by the programmer
  this->x_step = cos(direction) * speed;
  this->y_step = sin(direction) * speed;
}

void Actor::set_x(float x)
{
  this->x = x;
}

float Actor::get_x()
{
  return x;
}

void Actor::set_y(float y)
{
  this->y = y;
}

float Actor::get_y()
{
  return y;
}

void Actor::set_width(int width)
{
  this->width = width;
}

int Actor::get_width()
{
  return width;
}

void Actor::set_height(int height)
{
  this->height = height;
}

int Actor::get_height()
{
  return height;
}
  
int Actor::get_frame()
{
  return frame;
}

void Actor::set_frame(int frame)
{
  this->frame = frame;
}

void Actor::set_sprite(Image_Data* sprite)
{
  this->sprite = sprite;
}

Image_Data* Actor::get_sprite()
{
  return sprite;
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
