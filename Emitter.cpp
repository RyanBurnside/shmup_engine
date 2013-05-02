#include "Emitter.h"
#include <cmath>

using namespace std;

Emitter::Emitter(float x, float y, Image_Data* sprite, 
		 std::list<Bullet>* storage)
{
  //ctor
  this->x = x;
  this->y = y;
  this->direction = 0;
  this->halt_steps = 0;
  this->incriment_direction = 0.0;
  this->num_actions = 0;
  this->num_shots = 1;
  this->pointer_position = 0;
  this->shot_speed = 1.0;
  this->spread_angle = M_PI * 2.0;
  this->sprite = sprite;
  this->storage = storage;
  this->start_frame = 0;
}

Emitter::~Emitter()
{
  //dtor
}

void Emitter::add_attribute(int function_id, float parameter)
{
  // The int is a constant from the human-readable flags
  actions.push_back(function_id);
  parms.push_back(parameter);
  num_actions ++;
}

void Emitter::update()
{
  // Function sets member variables, pauses or fires off Bullet instances
  if(halt_steps == 0)
  {
    if(pointer_position >= num_actions)
      pointer_position = 0;
    
    int val = actions[pointer_position];
    switch(val)
    {
    case SHOT_NUMBER:
      // Set shot number
      num_shots = int(parms[pointer_position]);
      break;
      
    case SPREAD_ANGLE:
      // Set spread angle
      spread_angle = parms[pointer_position];
      break;
      
    case SHOT_SPEED:
      // Set speed of shots
      shot_speed = parms[pointer_position];
      break;
      
    case AIM_DIRECTION:
      // Set the direction Emitter is aiming
      direction = parms[pointer_position];
      break;
      
    case INCRIMENT_DIRECTION:
      // Set the amount to be incrimented with each update
      incriment_direction = parms[pointer_position];
      break;
        
    case PAUSE:
      // pause for x many steps
      halt_steps = parms[pointer_position];
      break;

    case FIRE:
      // Shoot with optional delay
      direction += incriment_direction;
      halt_steps = parms[pointer_position];
      float half_angle = spread_angle / 2.0;
      float aim_start = direction - half_angle;
      float step_angle = spread_angle / num_shots;

      for(unsigned int i = 0; i < num_shots; ++i)
      {
	float final_angle = aim_start + i * step_angle + (step_angle / 2.0);
	storage->push_back(Bullet(x, y, shot_speed, final_angle, 16, 16, 
				 sprite));
      }

      break;
    }
    pointer_position++;
  }
  else
  {
    halt_steps--;
  }
}

void Emitter::set_x(float x)
{
  this->x = x; 
}

void Emitter::set_y(float y)
{
  this->y = y;
}

float Emitter::get_x()
{
  return x;
}

float Emitter::get_y()
{
  return y;
}
