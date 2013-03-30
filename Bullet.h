#ifndef BULLET_H
#define BULLET_H
#include "Actor.h"

class Bullet : public Actor
{
  // Bullet class, optional gravity component, cycles through sprite frames
  // horizontal rotation frames, verticle animation frames for each angle
  
public:
  Bullet(float x, float y, float speed, float direction, int width, 
	 int height, Image_Data* sprite = 0);
    
  void set_gravity(float gravity);
  void set_gravity_direction(float gravity_direction);
  void update();
  void move();

  ~Bullet();
protected:
  
  int sprite_cycler; // iterates over sprite frames
  int sprite_offset; // offset from one animation frame to next

// These vars should never be adjusted directly, they affect each other
  float gravity_x_step;
  float gravity_y_step;
  float gravity;
  float gravity_direction;

  void calculate_gravity();
};

#endif // BULLET_H
