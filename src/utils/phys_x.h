#ifndef _PHYSX_H_
#define _PHYSX_H_


#define MAXIMUM_STATIC_BODIES 32
#define MAXIMUM_DYNAMIC_BODIES 16


// Коллайдер - левый верхний угол нулевая координата, плюс вправо вниз
struct collider
{
    unsigned char offset_x, offset_y;
    unsigned char width, height;
};

struct static_body
{
    unsigned char x, y;
    struct collider col;
};

struct dynamic_body
{
    unsigned char x, y;
    unsigned char vel_x, vel_y;
    struct collider col;
};


struct static_body static_bodies[MAXIMUM_STATIC_BODIES];
struct static_body dynamic_bodies[MAXIMUM_DYNAMIC_BODIES];


#endif