#ifndef _PLAYER_H_
#define _PLAYER_H_


#include "easy_Joy.h"

#include "oam.h"
#include "game_player_data.h"


extern struct player player_1;
extern void game_bullet_spawn(unsigned char x, unsigned char y, unsigned char velocity_x, unsigned char velocity_y);


void game_player_movement();
void game_player_shoot();
void game_player_oam();
void game_player_update();


#endif