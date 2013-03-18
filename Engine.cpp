#include "Engine.h"
#include "Emitter.h"

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
  Emitter e(120, 120, &rcore->sprites[0], &bullets);
  e.add_attribute(Emitter::SHOT_NUMBER, 4);
  e.add_attribute(Emitter::AIM_DIRECTION, 0.0);
  e.add_attribute(Emitter::SPREAD_ANGLE, 6.28);
  e.add_attribute(Emitter::SHOT_SPEED, 1.5);
  e.add_attribute(Emitter::INCRIMENT_DIRECTION, .2);
  e.add_attribute(Emitter::FIRE, 15);

  Emitter g(360, 120, &rcore->sprites[0], &bullets);
  g.add_attribute(Emitter::SHOT_NUMBER, 4);
  g.add_attribute(Emitter::AIM_DIRECTION, 3.14);
  g.add_attribute(Emitter::SPREAD_ANGLE, 6.28);
  g.add_attribute(Emitter::SHOT_SPEED, 1.5);
  g.add_attribute(Emitter::INCRIMENT_DIRECTION, -.2);
  g.add_attribute(Emitter::FIRE, 15);

  Emitter h(240, 120, &rcore->sprites[0], &bullets);
  h.add_attribute(Emitter::SHOT_NUMBER, 6);
  h.add_attribute(Emitter::AIM_DIRECTION, 3.14);
  h.add_attribute(Emitter::SPREAD_ANGLE, 6.28);
  h.add_attribute(Emitter::SHOT_SPEED, 1.5);
  h.add_attribute(Emitter::SET_FRAME, 1);
  for(int i = 0; i < 6; ++i)
  {
    h.add_attribute(Emitter::FIRE, 6); 
  }
  h.add_attribute(Emitter::AIM_DIRECTION, 6.28 / 12.0);
  h.add_attribute(Emitter::SET_FRAME, 0);
  for(int i = 0; i < 6; ++i)
  {
    h.add_attribute(Emitter::FIRE, 6); 
  }
  h.add_attribute(Emitter::PAUSE, 300);
  h.add_attribute(Emitter::FIRE, 30);
  h.add_attribute(Emitter::SHOT_NUMBER, 30);
  h.add_attribute(Emitter::SET_FRAME, 1);
  h.add_attribute(Emitter::FIRE, 30);
  h.add_attribute(Emitter::SET_FRAME, 0);
  h.add_attribute(Emitter::FIRE, 30);
  h.add_attribute(Emitter::SET_FRAME, 1);
  h.add_attribute(Emitter::FIRE, 30);
  h.add_attribute(Emitter::SET_FRAME, 0);
  h.add_attribute(Emitter::FIRE, 30);

  while(rcore->chk_quit() == false)
  {
    e.update();
    g.update();
    h.update();
    rcore->clear_screen();

    // Updates
    update_actors();
    rcore->blit_screen();
  }
}

void Engine::update_actors()
{
  std::list<Actor>::iterator iter = bullets.begin();
  while(iter != bullets.end())
  {
    if(iter->get_x() >= 0 && iter->get_y() >= 0 &&
       iter->get_x() <= rcore->get_width() && 
       iter->get_y() <= rcore->get_height())
    {
      iter->move();
      if(iter->get_sprite() != 0)
        // this is ugly code, fix all the crazy dereferences later
	rcore->draw_image(iter->get_sprite(), 
			  iter->get_x() - (iter->get_width() / 2.0),
			  iter->get_y() - (iter->get_height() / 2.0),
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
