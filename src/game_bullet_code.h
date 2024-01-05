#ifndef _BULLET_H_
#define _BULLET_H_


#include "oam.h"
#include "game_bullet_data.h"


extern unsigned char i, j, bullet_oam_index;
extern struct bullet bullets[];


void game_bullet_spawn(unsigned char x, unsigned char y, unsigned char velocity_x, unsigned char velocity_y);
void game_bullet_movement();
void game_bullet_oam();


#endif