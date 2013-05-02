#include "Engine.h"
#include "Emitter.h"
#include "Bullet.h"
#include "Ship.h"
#include "Path.h"
#include <time.h>
#include <sstream> // testing

Engine::Engine(int width, int height, std::string my_title = "")
{
  //ctor
  if(width < 1 || height < 1)
  {
    exit(1);
  }
  
  this->height = height;
  this->width = width;
  
  // Instanciate the graphics core
  this->rcore = new Render_Core(width, height);
  this->rcore->set_title(my_title);
}

void Engine::main_loop()
{
  Emitter h(0, 0, &rcore->sprites[0], &bullets);
  
  h.add_attribute(Emitter::AIM_DIRECTION, 3.14 / 2.0);
  h.add_attribute(Emitter::SHOT_NUMBER, 16);
  h.add_attribute(Emitter::SPREAD_ANGLE, 6.28);
  h.add_attribute(Emitter::SHOT_SPEED, 4);
  
  for(int i = 0; i < 3; ++i)
  {
    h.add_attribute(Emitter::FIRE, 60);
  }

  h.add_attribute(Emitter::INCRIMENT_DIRECTION, 0.0);
  h.add_attribute(Emitter::AIM_DIRECTION, 3.14 / 2.0);
  h.add_attribute(Emitter::SHOT_NUMBER, 2);
  h.add_attribute(Emitter::SPREAD_ANGLE, 6.28 / 4.0);
  h.add_attribute(Emitter::SHOT_SPEED, 3);
  for(int i = 0; i < 3; ++i)
  {
    h.add_attribute(Emitter::FIRE, 3); 
  }


  srand(time(NULL));
  int num_ships = 3;

  for(int j = 0; j < num_ships; ++j)
  {
    
    Ship s(rand() % 480, rand() % 240, .75, 
	   3.14 / 2.0, 32, 32, &rcore->sprites[4]);
    s.add_Emitter(h);
    ships.push_back(s);
  }
  std::stringstream ss; // used to append numbers to strings

  // timing taken from http://sdl.beuc.net/sdl.wiki/Time_Examples

  double nextFrame = static_cast<double>(SDL_GetTicks());
  while(1)
  {
    if(rcore->chk_quit() == true)
      exit(0);
    rcore->clear_screen();
    update_actors();
    if(nextFrame > static_cast<double>(SDL_GetTicks()))
    {
      rcore->blit_screen();
    }
    
    Uint32 delay = static_cast<Uint32>(nextFrame - 
				       static_cast<double>(SDL_GetTicks()));
    if(delay > 0)
    {
      SDL_Delay(delay);
    }
    nextFrame += 1000.0 / 60.0;
  } 
}   

void Engine::update_actors()
{
  //TODO look into templating all if possible

  int half_width, half_height;  
  float r_edge, l_edge, t_edge, b_edge;

  std::list<Ship>::iterator i;
  for(i = ships.begin(); i != ships.end(); ++i)
  {
    half_width = i->get_width() / 2; 
    half_height = i->get_height() / 2; 
    r_edge = i->get_x() + half_width;
    l_edge = i->get_x() - half_width;
    t_edge = i->get_y() - half_height;
    b_edge = i->get_y() + half_height;
    i->update();
    if(i->get_sprite() != 0)
	rcore->draw_image(i->get_sprite(), 
			  i->get_x() - half_width,
			  i->get_y() - half_height,
			  i->get_frame());
  }

  std::list<Bullet>::iterator iter = bullets.begin();
  while(iter != bullets.end())
  {
    half_width = iter->get_width() / 2; 
    half_height = iter->get_height() / 2; 
    r_edge = iter->get_x() + half_width;
    l_edge = iter->get_x() - half_width;
    t_edge = iter->get_y() - half_height;
    b_edge = iter->get_y() + half_height;
    iter->move();

    if(r_edge < 0 || b_edge < 0 || l_edge > width || t_edge > height)
    {
      // remove actor here
      iter = bullets.erase(iter);
    }
    else
    {
      if(iter->get_sprite() != 0)
	rcore->draw_image(iter->get_sprite(), 
			  iter->get_x() - half_width,
			  iter->get_y() - half_height,
			  iter->get_frame());
      ++iter;
    }
  }
}

Engine::~Engine()
{
  //dtor
  //clean up
  delete rcore;
}

//initialize static data for Engine class
std::list<Ship> Engine::ships;
