#ifndef RENDER_CORE_H
#define RENDER_CORE_H

#include <iostream>
#ifdef __APPLE__
#include <SDL/SDL.h>
#elif __linux__
#include <SDL/SDL.h>
#elif _WIN32
#include <SDL.h>
#endif

#include<string>
#include<vector>
#include<dirent.h>
#include<fstream>
#include<sstream>
#include "Image_Data.h"

// this render core is tailored to work with SDL
// this module will need to be rewritten should OpenGL or SFMl be used for other projects

struct Load_Data
{
  std::string fname;
  int w,h;
};

//TODO make Render_core a singleton
class Render_Core
{
public:
  Render_Core(short unsigned int width, short unsigned int height);
  short unsigned int get_width();
  short unsigned int get_height();
  bool chk_quit();
  virtual ~Render_Core();

  void set_title(const std::string &my_title);
  void draw_image(Image_Data*, int x, int y, int index);
  void draw_image_text(Image_Data*, int x, int y, std::string text);
  void clear_screen();
  void blit_screen();
  std::vector<Image_Data> sprites;

private:
  short unsigned int height;
  short unsigned int width;
  void load_sprites(const std::string &url);
  SDL_Surface* screen;
  SDL_Rect screen_rect;
};

#endif // RENDER_CORE_H
