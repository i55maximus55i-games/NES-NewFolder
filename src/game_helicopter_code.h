#ifndef _HELICOPTER_H_
#define _HELICOPTER_H_


#include "easy_Joy.h"

#include "oam.h"
#include "game_helicopter_data.h"


extern void game_bullet_spawn(unsigned char x, unsigned char y, unsigned char velocity_x, unsigned char velocity_y);

extern struct helicopter helicopter_1;
extern unsigned char i;

void game_helicopter_movement();
void game_helicopter_switch_state(unsigned char helicopter_state_next);
void game_helicopter_oam();
void game_helicopter_update();


#endif