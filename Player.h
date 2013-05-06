#include "Actor.h"

class Player : public Actor
{
public:
  Player(int x, int y, Image_Data* sprite, int width, int height, int lives);
  ~Player();

  void set_lives(int lives);
  int get_lives();

private:
  int bullet_timer;
  int lives;
};
