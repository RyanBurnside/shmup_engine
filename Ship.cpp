#include "Ship.h"

// This function is used for enemies who do not need a path and move in a linear fashon
Ship::Ship(float x, float y, float speed, float direction, int width, 
	   int height, Image_Data* sprite):
  Actor(x, y, speed, direction, width, height, sprite)
{
  // This ship has no path, we use the value 0
  this->path = 0;
  this->path_rate = 0;
  this->path_accumulator = 0.0;
  this->dead = false;
  std::cout << "Constructor finished" << std::endl;
}

// Overloaded function to include a path
// The path_rate is < 1 and defines the % step along the path
Ship::Ship(float x, float y, float speed, float direction, int width, int height, Image_Data* sprite, Path* path, float path_rate):
  Actor(x, y, speed, direction, width, height, sprite)
{
  // This constructor has a path, assign the path and the speed along path
  this->path = path;
  this->path_rate = path_rate;
  this->path_accumulator = 0.0;
  this->dead = false;
}

Ship::~Ship()
{
  
}

void Ship::add_Emitter(Emitter e)
{
  // Store an offset Point so the Emitters move with the change in x and y

  // Emitter x and y are relative, they are the offsets from ship (0,0)
  emitter_offsets.push_back(Point(e.get_x(), e.get_y()));
  emitters.push_back(e);
  std::cout << "Emitter added" << std::endl;

}

void Ship::update()
{
  // If the ship has no path, update direction
  // If the ship has a valid path, use the path instead
  // TODO kill the ship if at end of path OR outside screen

  if(path == 0)
  {
    Actor::move();
  }
  else
  {
    if(path_accumulator > 1)
    {
      dead = true;
    }
    if(!dead)
    {
      float num_points = path->points.size();
      // Use int rounding to find the nearest point
      Point p = path->points[int(path_accumulator * (num_points - 1) + .5)];
      x = p.x;
      y = p.y;
      path_accumulator += path_rate;
    }
  }

  // Update the Emitters and their relative x and y values
  if(!dead)
  {
    std::vector<Emitter>::iterator i;
    std::vector<Point>::iterator j = emitter_offsets.begin();
    for(i = emitters.begin(); i != emitters.end(); ++i, ++j)
    {
      i->set_x(x + j->x);
      i->set_y(y + j->y);
      i->update();
    }
  }
}
