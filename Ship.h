#ifndef SHIP_H
#define SHIP_H

#include "Actor.h"
#include "Path.h"
#include "Emitter.h"
#include "vector"

class Ship : public Actor
{
public:
  // dead should be set to true when the ship needs to be killed
  bool dead;

  // Ctors
  Ship(float x, float y, float speed, float direction, int width, 
       int height, Image_Data* sprite);
  Ship(float x, float y, float speed, float direction, int width, 
       int height, Image_Data* sprite, Path* path, 
       float path_rate);
  
  // Dtor
  virtual ~Ship();

  // Methods
  virtual void add_Emitter(Emitter e);
  virtual void update();

protected:
  Path* path;
  // Step % along path per frame
  float path_rate;
  // Accumulator for path % starts at 0, should be 1 or greater when done
  float path_accumulator;

  std::vector<Point> emitter_offsets;
  std::vector<Emitter> emitters;
};

#endif // SHIP_H
