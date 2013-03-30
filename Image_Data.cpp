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
  num_horizontal = this->base_image->w / frame_w;
  num_vertical = this->base_image->h / frame_h;
  std::cout << "Num across " << num_horizontal << " num down " << num_vertical << std::endl;
  
  // Ensure passed frame_w and frame_h are valid
  if(this->base_image->w % frame_w || this->base_image->h % frame_h )
  {
    std::cout << "frame_w or frame_h is incorrect for " << fname << std::endl;
    exit(1);
  }
  
  // Generate the SDL rectangles for subimages
  for(int y = 0; y < num_vertical; ++y)
  {
    for(int x = 0; x < num_horizontal; ++x)
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
