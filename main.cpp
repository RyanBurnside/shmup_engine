#include "Engine.h"

// testing only remove all headers below for release
//#include "Actor.h"
//#include "Emitter.h"
//#include "Path.h"
//#include "Render_Core.h"
//#include "Ship.h"

int main ( int argc, char** argv )
{
  // initialize SDL video
  Engine game(480, 640, "Shmup Framework Engine Test");
  game.main_loop();
  return 0;
}
