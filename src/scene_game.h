#ifndef _SCENE_GAME_H_
#define _SCENE_GAME_H_

#include "scene.h"
#include "render_utils.h"
#include "game_cycle.h"

extern char nmi_oam_enable;
#pragma zpsym ("nmi_oam_enable");

typedef struct {
    unsigned char y;
    unsigned char tile_index;
    unsigned char attributes;
    unsigned char x;
} sprite_t;
extern sprite_t oam_shadow[];

void scene_game_start() {
    render_disable();

    fill_nametable(0, 0x00);

    wait_for_vblank();
    PPU_MASK = MASK_SHOW_BG | MASK_SHOW_SPRITE | MASK_SHOW_LEFT_BG | MASK_SHOW_LEFT_SPRITE;
    PPU_CTRL = CTRL_NAMETABLE_2000 | CTRL_INCREMENT_1 | CTRL_SPRITE_0000 | CTRL_BG_1000 | CTRL_SPRITE_8x16 | CTRL_NMI_ENABLE;
    PPU_SCROLL = 0; PPU_SCROLL = 0;


}
void scene_game_render() 
{
    while (1)
    {
        // TODO:
        /*
            Player:
                movement
                shoot
                sprite

            Enemy
            Helicopter

            Camera
            Levels
        */
        game_update();

        nmi_oam_enable = 0x02;

        wait_for_nmi();
    }
}
void scene_game_end() {}

struct scene scene_game = { scene_game_start, scene_game_render, scene_game_end };

#endif