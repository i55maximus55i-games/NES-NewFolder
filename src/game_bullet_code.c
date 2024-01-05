#include "game_bullet_code.h"


void game_bullet_oam()
{
    for (j = 0; j < 4; ++j)
    {
        oam_shadow[4 + j].x = 0;
        oam_shadow[4 + j].y = 241;
        oam_shadow[4 + j].tile_index = 0x1A;
        oam_shadow[4 + j].attributes = 0;
    }

    j = 0;
    if (bullet_oam_index >= BULLETS_MAX_COUNT) bullet_oam_index = 0;
    for (i = bullet_oam_index; i < BULLETS_MAX_COUNT; ++i)
    {
        if (bullets[i].active)
        {
            oam_shadow[4 + j].x = bullets[i].x;
            oam_shadow[4 + j].y = bullets[i].y;
            oam_shadow[4 + j].tile_index = 0x1A;
            oam_shadow[4 + j].attributes = 0;

            bullet_oam_index = i + 1;
            ++j;
            if (j > 3) return;
        }
    }
    bullet_oam_index = 0;
}
void game_bullet_movement()
{
    for (i = 0; i < 64; ++i)
    {
        if (bullets[i].active)
        {
            bullets[i].x += bullets[i].velocity_x;
            bullets[i].y += bullets[i].velocity_y;

            if (bullets[i].x < 7 || bullets[i].y < 7) bullets[i].active = 0;
        }
    }
}
void game_bullet_spawn(unsigned char x, unsigned char y, unsigned char velocity_x, unsigned char velocity_y)
{
    for (i = 0; i < BULLETS_MAX_COUNT; ++i)
    {
        if (bullets[i].active == 0)
        {
            bullets[i].x = x;
            bullets[i].y = y;
            bullets[i].velocity_x = velocity_x;
            bullets[i].velocity_y = velocity_y;
            bullets[i].active = 1;
            break;
        }
    }
}