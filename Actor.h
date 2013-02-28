#ifndef ACTOR_H
#define ACTOR_H

#include "Image_Data.h"

class Actor
{
    // This class provides a generic object for game objects to extend
    // it is probably best for objects that simply move and have a sprite

    public:
        float x;
        float y;
        int width;
        int height;
        Image_Data* sprite;
        Actor(float x, float y, float speed, float direction, int width, int height, Image_Data* sprite);

        void set_direction(float dir);
        float get_direction();
        void set_speed(float new_speed);
        float get_speed();

        void move();
        virtual ~Actor();

    protected:
        // These vars should never be adjusted directly, they affect each other
        float x_step;
        float y_step;
        float speed;
        float direction;
};

#endif // ACTOR_H
