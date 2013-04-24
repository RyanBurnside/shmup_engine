#ifndef EMITTER_H
#define EMITTER_H

#include "Bullet.h"
#include <list>

// Each path will contain a std::vector of function pointers so each
// Emitter can be configured differently using the std::vector as an script

struct EmitterAction
{
  int action;
  float parameter;
};

class Emitter
{
public:
  Emitter(float x, float y, Image_Data* sprite, std::list<Bullet>* storage);
  virtual ~Emitter();

  enum{SHOT_NUMBER, SPREAD_ANGLE, SHOT_SPEED, AIM_DIRECTION, 
       INCRIMENT_DIRECTION, PAUSE, FIRE};

  void add_attribute(int function_id, float parameter);
  void update();
  void set_x(float x);
  void set_y(float y);
  float get_x();
  float get_y();

private:
  float x, y;
  unsigned int start_frame;
  std::vector<int> actions; // Works on enum table for function name
  std::vector<float> parms;
  Image_Data* sprite;
  std::list<Bullet>* storage;

  // Contains the position in the list
  int pointer_position; // Position of the instruction pointer
  unsigned int num_shots, halt_steps;
  unsigned int num_actions;
  float spread_angle, shot_speed, direction, incriment_direction;
};
#endif // EMITTER_H
