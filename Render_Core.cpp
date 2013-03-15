#include "Render_Core.h"


Render_Core::Render_Core(int width, int height)
{
  //ctor
  if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
  {
    printf( "Unable to init SDL: %s\n", SDL_GetError() );
    exit(1);
    //return 1;
  }
  
  // make sure SDL cleans up before exit
  atexit(SDL_Quit);
  
  // create a new window
  screen = SDL_SetVideoMode(width, height, 16,
			    SDL_HWSURFACE|SDL_DOUBLEBUF);
  
  if ( !screen )
  {
    printf("Unable to set video: %s\n", SDL_GetError());
    exit(1);
    //return 1;
  }
  screen_rect = (SDL_Rect){0,0,width, height};
  
  // set height and width
  this->height = height;
  this->width = width;
  
  // load_sprites here
  load_sprites("./images");
}


int Render_Core::get_width()
{
  return width;
}

int Render_Core::get_height()
{
  return height;
}

void Render_Core::load_sprites(const std::string &url)
{
  // use images/sprite_info.dat to make sprites
  // file has line format name,cell_width,cell_height<newline>
  
  std::ifstream config("images/sprite_info.dat");
  std::string line_value, sub_w, sub_h;
  std::stringstream converter;
  int w_size, h_size;
  
  
  if(config.is_open())
  {
    std::cout << "Found images/sprite_info.dat\n";
    while(config.good())
    {
      std::getline(config, line_value);
      std::string name = line_value.substr(0,
					   line_value.find_first_of(','));
      
      // read through the sprite data file and create images
      if(name != "")
      {
	std::cout << "Name " << name << std::endl;
	line_value = line_value.substr(line_value.find_first_of(',')+1);
	sub_w = line_value.substr(line_value.find_first_of(',')+1,
				  line_value.find_last_of(','));
	
	sub_h = line_value.substr(line_value.find_last_of(',') + 1);
	
	// use a string stream to convert string sizes to ints
	converter.clear();
	converter << sub_w;
	converter >> w_size;
	converter.clear();
	converter << sub_h;
	converter >> h_size;
	
	// now create the Image_data object and add it to the vector
	sprites.push_back(Image_Data("images/"+name, name,
				     w_size, h_size));
      }
    }
    config.close();
  }
  else
  {
    std::cout << "File images/sprite_info.dat not found!";
    exit(1);
  }
  
}

bool Render_Core::chk_quit()
{
  // message processing loop
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    // check for messages
    switch (event.type)
    {
      // exit if the window is closed
    case SDL_QUIT:
      return true;
      // check for keypresses
    case SDL_KEYDOWN:
    {
      // exit if ESCAPE is pressed
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return true;
    }
    } // end switch
  } // end of message processing
  return false;
}

void Render_Core::draw_image(Image_Data* sprite, int x, int y, int index = 0)
{
  // draw the Image_Data to the screen
  // 0 is by default the first image, -1 will be the last
  SDL_Rect end;
  end.x = x;
  end.y = y;
  end.w = width - x;
  end.h = height - y;
  SDL_BlitSurface(sprite->base_image, &sprite->frames[index], screen, &end);
}

void Render_Core::clear_screen()
{
  // clear screen
  SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 31, 31, 63));
}

void Render_Core::blit_screen()
{
  // finally, update the screen :)
  SDL_Flip(screen);
}
void Render_Core::set_title(const std::string &my_title)
{
  SDL_WM_SetCaption(my_title.c_str(), 0);
}

Render_Core::~Render_Core()
{
}
