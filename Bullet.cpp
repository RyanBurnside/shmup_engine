#include "Bullet.h"
#include <cmath>
#include <iostream>

Bullet::Bullet(float x, float y, float speed, float direction, int width, 
	       int height, Image_Data* sprite):
  Actor(x, y, speed, direction, width, height, sprite)
{
  gravity = 15;
  gravity_direction = 0;
  gravity_x_step = 0;
  gravity_y_step = 0;

  //TODO set up initial subimage based on number of frames in image data
  sprite_cycler = 0; // iterates over sprite frames
  sprite_offset = 0; // offset from one animation frame to next
  sprite_offset = sprite->num_across();

  //TODO fix angular error
  float angle_offset = 6.28 / (sprite->num_across() / 2.0);
  frame = int(direction / 6.28 * 15 + angle_offset);
  if(frame >= sprite->num_across() - 1)
    frame -= sprite->num_across() - 1;
}

void Bullet::set_gravity(float gravity)
{
  this->gravity = gravity;
  calculate_gravity();
}

void Bullet::set_gravity_direction(float gravity_direction)
{
  this->gravity_direction = gravity_direction;
  calculate_gravity();
}

void Bullet::calculate_gravity()
{
  gravity_x_step = cos(gravity_direction) * gravity;
  gravity_y_step = sin(gravity_direction) * gravity;  
}

void Bullet::update()
{
//TODO sprite cycle


}

void Bullet::move()
{
  //TODO add gravity
  x += x_step;
  y += y_step;
}

Bullet::~Bullet()
{
  //dtor
}
