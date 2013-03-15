#include "Engine.h"


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
  
  // create some bullets for fun
  for(int y = 0; y < 1500; ++y)
  {
    float r = (float)rand()/(float)RAND_MAX;
    float d = (float)rand()/(float)RAND_MAX * 6.28;
    bullets.push_back(Actor(320, 240, r * 3 + .1, d, 
			      16, 16, &rcore->sprites[0]));
      
  }
  std::cout << "size of bullets is " << bullets.size() << std::endl;
  while(rcore->chk_quit() == false)
  {
    rcore->clear_screen();
    //updates
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
	// YOU NEED TO ADD A CUE|RRENT FRAME VAR to the Image_Data type
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
