#include "Engine.h"


Engine::Engine(int width, int height, std::string my_title = "")
{
    //ctor
    if(width < 1 || height < 1)
    {
        std::cout << "Could not create window, check values for Engine.." << std::endl;
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
    for(int y = 0; y < 16; ++y)
    {
        for(int x = 0; x < 16; ++x)
        {
            bullets.push_back(Actor(x*8, y*8, 0, 0, 8, 8, &rcore->sprites[1]));
            std::cout << "size of bullets is " << bullets.size() << std::endl;
        }
    }
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
        if(iter->x >= 0 && iter->y >= 0 &&
           iter->x <= rcore->get_width() && iter->y <= rcore->get_height())
        {
            iter->move();
            if(iter->sprite != 0)
                rcore->draw_image(iter->sprite, iter->x, iter->y, 65);
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
