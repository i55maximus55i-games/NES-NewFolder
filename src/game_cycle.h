#ifndef _GAMECYCLE_H_
#define _GAMECYCLE_H_


#include "oam.h"
#include "rapidfire.h"
#include "game_player_code.h"
#include "game_bullet_code.h"
#include "game_helicopter_code.h"


void game_update();
void game_player_shoot();
void game_update_ppu();


#endif