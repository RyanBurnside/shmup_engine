#include "Bullet.h"
#include <cmath>

Bullet::Bullet(float x, float y, float speed, float direction, int width, 
	       int height, Image_Data* sprite):
  Actor(x, y, speed, direction, width, height, sprite)
{
  gravity = 0;
  gravity_direction = 0;
  gravity_x_step = 0;
  gravity_y_step = 0;

  //TODO set up initial subimage based on number of frames in image data
  sprite_cycler = 0; // iterates over sprite frames
  sprite_offset = sprite->num_across();

  // Only apply rotation subimages if num rotation sprites is > 1
  // This is costly so it should be avoided for non rotating images
  if(sprite->num_across() > 1)
  {
    frame = (int)round(direction / (M_PI * 2) * sprite->num_across()) % 
      sprite->num_across();
  }
  else
  {
    frame = 0;
  }
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
