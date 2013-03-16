#ifndef EMITTER_H
#define EMITTER_H

#include <vector>

// each path will contain a vector of function pointers so each
// Emitter can be configured differently using the vector as an script



struct EmitterAction
{
  int action;
  float parameter;
};

class Emitter
{
public:
  Emitter();
  virtual ~Emitter();
  // flags which are keys for the functon setter function
  static const int SHOT_NUMBER;
  static const int SPREAD_ANGLE;
  static const int SHOT_SPEED;
  static const int AIM_DIRECTION;
  static const int INCRIMENT_DIRECTION;
  static const int PAUSE;
  static const int FIRE;
  void add_attribute(int function_id, float parameter);
  void update();
  
private:
  std::vector<int> actions; // works on enum table for function name
  std::vector<float> parms;
  
  // contains the position in the list
  int pointer_position; // position of the instruction pointer
  int num_shots, halt_steps;
  int num_actions;
  float spread_angle, shot_speed, direction;
};




#endif // EMITTER_H
