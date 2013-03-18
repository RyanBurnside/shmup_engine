#include "Image_Data.h"

Image_Data::Image_Data(std::string pathname, std::string fname, int frame_w,
                       int frame_h)
{
  this->pathname = pathname;
  this->fname = fname;
  this->frame_w = frame_w;
  this->frame_h = frame_h;

  // Load SDL_bitmap
  this-> base_image = SDL_LoadBMP(pathname.c_str());
  
  // Create our SDL_rects
  float num_across, num_down;
  num_across = this->base_image->w / frame_w;
  num_down = this->base_image->h / frame_h;
  std::cout << "Num across " << num_across << " num down " << num_down << std::endl;
  
  // Ensure passed frame_w and frame_h are valid
  if(this->base_image->w % frame_w || this->base_image->h % frame_h )
  {
    std::cout << "frame_w or frame_h is incorrect for " << fname << std::endl;
    exit(1);
  }
  
  // Generate the SDL rectangles for subimages
  for(int y = 0; y < num_down; ++y)
  {
    for(int x = 0; x < num_across; ++x)
    {
      this->frames.push_back((SDL_Rect)
			     {x * frame_w, y * frame_h, frame_w, frame_h});
    }
  }

  SDL_SetColorKey(this->base_image, SDL_SRCCOLORKEY, 
		  SDL_MapRGB(this->base_image->format, 255, 0, 255));
  
  std::cout << "Loaded" << fname << std::endl;
}

Image_Data::~Image_Data()
{
  // Causes a double free, look into this!
  //SDL_FreeSurface(base_image);
}
