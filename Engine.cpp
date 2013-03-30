#include "Engine.h"
#include "Emitter.h"
#include "Bullet.h"

Engine::Engine(int width, int height, std::string my_title = "")
{
  //ctor
  if(width < 1 || height < 1)
  {
    std::cout << "Could not create window, check values for Engine..\n" ;
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
  
  Emitter h(240, 120, &rcore->sprites[2], &bullets);
  h.add_attribute(Emitter::SHOT_NUMBER, 32);
  h.add_attribute(Emitter::AIM_DIRECTION, 3.14);
  h.add_attribute(Emitter::SPREAD_ANGLE, 6.28);
  h.add_attribute(Emitter::SHOT_SPEED, 1.5);
  h.add_attribute(Emitter::FIRE, 30); 

  while(rcore->chk_quit() == false)
  {
    h.update();
    rcore->clear_screen();

    // Updates
    update_actors();
    rcore->blit_screen();
  }
}

void Engine::update_actors()
{
  //TODO look into templating all if possible
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

    if((r_edge >= 0 && b_edge >= 0) &&
       (l_edge <= rcore->get_width() && 
	t_edge <= rcore->get_height()))
    {
      if(iter->get_sprite() != 0)
        // this is ugly code, fix all the crazy dereferences later
	rcore->draw_image(iter->get_sprite(), 
			  iter->get_x() - half_width,
			  iter->get_y() - half_height,
			  iter->get_frame());
      iter++;
    }
    else
    {
      // remove actor here
      iter = bullets.erase(iter);
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
