#ifndef _SCENE_TITLE_H_
#define _SCENE_TITLE_H_

#include "scene.h"
#include "render_utils.h"

extern unsigned char x, y, i;
extern char lang_title_new_folder_1[];
extern char lang_title_new_folder_2[];
extern char lang_title_new_folder_3[];
extern char lang_title_new_folder_4[];
extern char lang_title_new_folder_5[];
extern char lang_title_new_folder_6[];

extern struct scene scene_mainmenu;

void scene_title_start() 
{
    render_disable();

    fill_nametable(0, 0x00);

    PPU_ADDR = 0x20; PPU_ADDR = 0x21;
    print_string(lang_title_new_folder_1);
    PPU_ADDR = 0x20; PPU_ADDR = 0xE1;
    print_string(lang_title_new_folder_2);
    print_string(lang_title_new_folder_3);
    PPU_ADDR = 0x21; PPU_ADDR = 0xC1;
    print_string(lang_title_new_folder_4);
    print_string(lang_title_new_folder_5);
    PPU_ADDR = 0x23; PPU_ADDR = 0x01;
    print_string(lang_title_new_folder_6);

    wait_for_vblank();
    PPU_MASK = MASK_SHOW_BG | MASK_SHOW_SPRITE | MASK_SHOW_LEFT_BG | MASK_SHOW_LEFT_SPRITE;
    PPU_CTRL = CTRL_NAMETABLE_2000 | CTRL_INCREMENT_1 | CTRL_SPRITE_0000 | CTRL_BG_1000 | CTRL_SPRITE_8x8 | CTRL_NMI_ENABLE;
    PPU_SCROLL = 0; PPU_SCROLL = 0;

    i = 0;
    famistudio_music_play(0);
}

void scene_title_render() 
{
    while (1)
    {
        ++i;
        if (i > 1)
        {
            break;
        }
        wait_for_nmi();
    }
    set_scene(&scene_mainmenu);
}

void scene_title_end()
{
    famistudio_music_pause(FAMISTUDIO_PAUSE);
}

struct scene scene_title = { scene_title_start, scene_title_render, scene_title_end };

#endif