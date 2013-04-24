#include "Engine.h"
#include "Emitter.h"
#include "Bullet.h"
#include "Ship.h"
#include "Path.h"
#include <time.h>

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
  h.add_attribute(Emitter::SPREAD_ANGLE, 6.28);
  h.add_attribute(Emitter::SHOT_SPEED, 4.5);
  for(int i = 0; i < 50; ++i)
  {
    h.add_attribute(Emitter::SHOT_NUMBER, i);
    h.add_attribute(Emitter::FIRE, 5); 
  }
  h.add_attribute(Emitter::PAUSE, 10); 
  h.add_attribute(Emitter::SHOT_NUMBER, 30);
  h.add_attribute(Emitter::INCRIMENT_DIRECTION, 6.28 / 100);
  for(int i = 0; i < 50; ++i)
  {
    h.add_attribute(Emitter::FIRE, 5); 
  }
  h.add_attribute(Emitter::SHOT_NUMBER, 12);

  h.add_attribute(Emitter::INCRIMENT_DIRECTION, 0.0);  
  for(int i = 0; i < 50; ++i)
  {  
    h.add_attribute(Emitter::AIM_DIRECTION, 3.14 / 2.0);
    h.add_attribute(Emitter::SPREAD_ANGLE, i / 49.0 * 6.28);
    h.add_attribute(Emitter::FIRE, 0);
    h.add_attribute(Emitter::AIM_DIRECTION, 6.28 * .75);
    h.add_attribute(Emitter::SPREAD_ANGLE, i / 49.0 * 6.28);
    h.add_attribute(Emitter::FIRE, 0); 
  }
  srand (time(NULL));
  std::vector<Point> path_points;
  for(int i = 0; i < 4; ++i)
  {
    path_points.push_back(Point(rand() % 480, rand() % 640));
  }

  Path pathy(path_points, 1000);
  Ship s(240.0, 0.0, .3, 3.14 / 2.0, 24, 24, &rcore->sprites[1], &pathy, .001);
  s.add_Emitter(h);
  while(rcore->chk_quit() == false)
  {
	rcore->clear_screen();
	rcore->draw_image_text(&rcore->sprites[1], 0, 0, 
				 "Bullet Hell Engine");
	s.update();
	update_actors();
	rcore->blit_screen();
  }
}

void Engine::update_actors()
{
  //TODO look into templating all if possible

  std::list<Ship>::iterator i;
  for(i = ships.begin(); i != ships.end(); ++i)
  {
    i->update();

  }

  std::list<Bullet>::iterator iter = bullets.begin();
  int half_width, half_height;  
  float r_edge, l_edge, t_edge, b_edge;

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
