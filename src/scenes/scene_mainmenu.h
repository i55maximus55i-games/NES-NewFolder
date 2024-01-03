#ifndef _SCENE_MAINMENU_H_
#define _SCENE_MAINMENU_H_

#include "scene.h"
#include "../utils/render_utils.h"

void scene_mainmenu_start() {
    render_disable();

    fill_nametable(0, 0x00);

    wait_for_vblank();
    PPU_MASK = MASK_SHOW_BG | MASK_SHOW_SPRITE | MASK_SHOW_LEFT_BG | MASK_SHOW_LEFT_SPRITE;
    PPU_CTRL = CTRL_NAMETABLE_2000 | CTRL_INCREMENT_1 | CTRL_SPRITE_1000 | CTRL_BG_0000 | CTRL_SPRITE_8x8 | CTRL_NMI_ENABLE;
    PPU_SCROLL = 0; PPU_SCROLL = 0;

    i = 0;
}
void scene_mainmenu_render() 
{
    while (1)
    {
        wait_for_nmi();
    }
}
void scene_mainmenu_end() {}

struct scene scene_mainmenu = { scene_mainmenu_start, scene_mainmenu_render, scene_mainmenu_end };

#endif