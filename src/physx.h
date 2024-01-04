#ifndef _PHYSX_H_
#define _PHYSX_H_


#define MAXIMUM_STATIC_BODIES 16
#define MAXIMUM_DYNAMIC_BODIES 64


// Коллайдер - левый верхний угол нулевая координата, плюс вправо вниз
struct collider
{
    unsigned char offset_x, offset_y;
    unsigned char width, height;
};

struct static_body
{
    unsigned char active;
    
    int x, y;
    struct collider col;
};

struct dynamic_body
{
    unsigned char active;

    int x, y;
    int vel_x, vel_y;
    struct collider col;
};

struct static_body static_bodies[MAXIMUM_STATIC_BODIES];
struct dynamic_body dynamic_bodies[MAXIMUM_DYNAMIC_BODIES];

void physx_update()
{
    for (i = 0; i < MAXIMUM_DYNAMIC_BODIES; ++i)
    {
        dynamic_bodies[MAXIMUM_DYNAMIC_BODIES].x += dynamic_bodies[MAXIMUM_DYNAMIC_BODIES].vel_x;
        dynamic_bodies[MAXIMUM_DYNAMIC_BODIES].y += dynamic_bodies[MAXIMUM_DYNAMIC_BODIES].vel_y;
    }
}


#endif