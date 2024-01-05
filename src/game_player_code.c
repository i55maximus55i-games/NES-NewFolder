#include "game_player_code.h"


void game_player_oam()
{
    oam_shadow[0].x = player_1.x;
    oam_shadow[0].y = player_1.y;
    oam_shadow[0].tile_index = 0x1C;

    oam_shadow[1].x = player_1.x + 8;
    oam_shadow[1].y = player_1.y;
    oam_shadow[1].tile_index = 0x1E;
}

void game_player_movement()
{
    if (JOY1_HELD & BUTTON_RIGHT)   ++player_1.x;
    if (JOY1_HELD & BUTTON_LEFT)    --player_1.x;
    if (JOY1_HELD & BUTTON_UP)      --player_1.y;
    if (JOY1_HELD & BUTTON_DOWN)    ++player_1.y;
}

void game_player_shoot()
{
    if (JOY1_RELEASED & BUTTON_A)
    {
        game_bullet_spawn(player_1.x + 20, player_1.y + 6, 3, 0); // TODO: скорректировать точку спавна
    }
}

void game_player_update()
{
    game_player_movement();
    game_player_shoot();
}