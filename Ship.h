#ifndef SHIP_H
#define SHIP_H
#include "Actor.h"
#include "Path.h"
#include "Emitter.h"
#include "vector"

class Ship : public Actor
{
public:
  Ship();
  Ship(float x, float y, float speed, float direction, int width, int height, Image_Data* sprite = 0);
  Ship(float x, float y, float speed, float direction, int width, int height, Image_Data* sprite = 0, Path* path = 0);
  virtual ~Ship();
  // TODO add accessor methods for the emitter container below.
  

protected:
  Path* path;
  std::vector<Emitter> emitters;
};

#endif // SHIP_H
