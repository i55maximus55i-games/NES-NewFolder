#ifndef _BULLET_DATA_H_
#define _BULLET_DATA_H_


#define BULLETS_MAX_COUNT 32

struct bullet
{
    unsigned char x, y;
    unsigned char velocity_x, velocity_y;
    unsigned char active;
};


#endif