#ifndef _SCENE_GAME_H_
#define _SCENE_GAME_H_

#include "scene.h"
#include "render_utils.h"
#include "game_cycle.h"


struct player player_1;
struct helicopter helicopter_1;
struct bullet bullets[BULLETS_MAX_COUNT];


void scene_game_start() {
    render_disable();

    fill_nametable(0, 0x00);

    wait_for_vblank();
    PPU_MASK = MASK_SHOW_BG | MASK_SHOW_SPRITE | MASK_SHOW_LEFT_BG | MASK_SHOW_LEFT_SPRITE;
    PPU_CTRL = CTRL_NAMETABLE_2000 | CTRL_INCREMENT_1 | CTRL_SPRITE_0000 | CTRL_BG_1000 | CTRL_SPRITE_8x16 | CTRL_NMI_ENABLE;
    PPU_SCROLL = 0; PPU_SCROLL = 0;

    // TODO: reset game
}
void scene_game_render() 
{
    while (1)
    {
        game_update();
    }
}
void scene_game_end() {}

struct scene scene_game = { scene_game_start, scene_game_render, scene_game_end };

#endif