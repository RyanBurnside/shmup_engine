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
  
  // instanciate the new graphics core
  this->rcore = new Render_Core(width, height);
  this->rcore->set_title(my_title);
}

void Engine::main_loop()
{

  // Make a bullet emitter to test
  Emitter e(120, 120, &rcore->sprites[0], &bullets); 
  e.add_attribute(e.SHOT_NUMBER, 20);
  e.add_attribute(e.SHOT_SPEED, 3);
  e.add_attribute(e.SPREAD_ANGLE, 360);
  e.add_attribute(e.FIRE, 2);

  Emitter f(240, 120, &rcore->sprites[0], &bullets); 
  f.add_attribute(f.SHOT_NUMBER, 20);
  f.add_attribute(f.SHOT_SPEED, 3);
  f.add_attribute(f.SPREAD_ANGLE, 360);
  f.add_attribute(f.FIRE, 2);

  Emitter g(360, 120, &rcore->sprites[0], &bullets); 
  g.add_attribute(g.SHOT_NUMBER, 20);
  g.add_attribute(g.SHOT_SPEED, 3);
  g.add_attribute(g.SPREAD_ANGLE, 360);
  g.add_attribute(g.FIRE, 2);

  while(rcore->chk_quit() == false)
  {
    e.update();
    f.update();
    g.update();
    rcore->clear_screen();

    // Updates
    update_actors();
    rcore->blit_screen();
  }
}

void Engine::update_actors()
{
  std::list<Actor>::iterator iter;
  for(iter = bullets.begin(); iter != bullets.end(); ++iter)
  {
    if(iter->get_x() >= 0 && iter->get_y() >= 0 &&
       iter->get_x() <= rcore->get_width() && iter->get_y() <= rcore->get_height())
    {
      iter->move();
      if(iter->get_sprite() != 0)
	// TODO this currently just draws frame 0
	// YOU NEED TO ADD A CUERRENT FRAME VAR to the Image_Data type
	rcore->draw_image(iter->get_sprite(), iter->get_x(), iter->get_y(), 0);
    }
    else
    {
      // remove actor here
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
