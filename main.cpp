#include "Engine.h"

int main ( int argc, char** argv )
{
  // initialize SDL video
  Engine game(480, 640, "Shmup Framework Engine Test");
  game.main_loop();
  return 0;
}
