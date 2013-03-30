#ifndef IMAGE_DATA_H_INCLUDED
#define IMAGE_DATA_H_INCLUDED
#ifdef __APPLE__
#include <SDL/SDL.h>
#elif __linux__
#include <SDL/SDL.h>
#elif _WIN32
#include <SDL.h>
#endif

#include<iostream>
#include<vector>
#include<string>


// Image data class is designed to simply point to a stored SDL_Surface and never to delete one
class Image_Data
{
public:
  SDL_Surface * base_image; // No idea why this can't be private
  std::vector<SDL_Rect> frames;
  Image_Data(std::string pathname, std::string fname, int frame_w, 
	     int frame_h);
  ~Image_Data();
  
  int get_w()
  {
    return frame_w;
  }
  
  int get_h()
  {
    return frame_h;
  }

  int num_across()
  {
    return num_horizontal;
  }

  int num_down()
  {
    return num_vertical;
  }

  
  std::string get_fname()
  {
    return fname;
  }
  
  int count_frames()
  {
    return frames.size();
  }

private:
  std::string fname, pathname;
  int frame_w, frame_h, num_horizontal, num_vertical;
};

#endif // IMAGE_DATA_H_INCLUDED
