#ifndef ENGINE_H
#define ENGINE_H

//include the classes we might need
#include "Render_Core.h"
#include <iostream>
#include <list>
#include "Ship.h"
#include <cstdlib> // gcc needs this for exit()

class Engine
{
public:
  static std::list<Ship> ships;
  Engine(int width, int height, std::string my_title); // may not invoke create directly
  void main_loop();
  virtual ~Engine();
  
private:
  int height, width;
  Render_Core* rcore;
  std::list<Actor> enemies;
  std::list<Actor> players;
  std::list<Actor> bullets;
  std::string game_title;
  
  void update_actors();
};
#endif // ENGINE_H
