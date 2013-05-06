#include "Player.h"

Player::Player(int x, int y, Image_Data* sprite, int width, int height, 
	       int lives) :
  Actor(x, y, 0, 0, width, height, sprite)
{
  this->lives = lives;
}

Player::~Player(){};

void Player::set_lives(int lives)
{
  this->lives = lives;
}

int Player::get_lives()
{
  return lives;
}
