#ifndef ACTOR_H
#define ACTOR_H

#include "Image_Data.h"

class Actor
{
  // This class provides a generic object for game objects to extend
  // it is probably best for objects that simply move and have a sprite
  
public:
  Actor(float x, float y, float speed, float direction, int width, int height, 
	Image_Data* sprite = 0, int frame = 0);
  
  virtual void set_x(float x);
  virtual float get_x();
  
  virtual void set_y(float y);
  virtual float get_y();
  
  virtual void set_width(int width);
  virtual int get_width();
  
  virtual void set_height(int height);
  virtual int get_height();
  
  virtual int get_frame();
  virtual void set_frame(int frame);

  virtual void set_sprite(Image_Data* sprite);
  virtual Image_Data* get_sprite();
  
  virtual void set_direction(float dir);
  virtual float get_direction();
  
  virtual void set_speed(float new_speed);
  virtual float get_speed();
  virtual void move();
  
  virtual ~Actor();
  
protected:
  float x;
  float y;
  int width;
  int height;
  int frame;
  Image_Data* sprite;
  
  // These vars should never be adjusted directly, they affect each other
  float x_step;
  float y_step;
  float speed;
  float direction;
};

#endif // ACTOR_H
