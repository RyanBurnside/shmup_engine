#ifndef EMITTER_H
#define EMITTER_H

#include "Bullet.h"
#include "Image_Data.h"
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

  // Flags which are keys for the functon setter function
  static const int SHOT_NUMBER;
  static const int SPREAD_ANGLE;
  static const int SHOT_SPEED;
  static const int AIM_DIRECTION;
  static const int INCRIMENT_DIRECTION;
  static const int PAUSE;
  static const int SET_FRAME;
  static const int FIRE;

  void add_attribute(int function_id, float parameter);
  void update();
  void set_x(float x);
  void set_y(float y);
  float get_x();
  float get_y();

private:
  float x, y;
  int start_frame;
  std::vector<int> actions; // works on enum table for function name
  std::vector<float> parms;
  Image_Data* sprite;
  std::list<Bullet>* storage;

  // Contains the position in the list
  int pointer_position; // position of the instruction pointer
  int num_shots, halt_steps;
  int num_actions;
  float spread_angle, shot_speed, direction, incriment_direction;
};
#endif // EMITTER_H
