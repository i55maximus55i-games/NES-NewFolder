#include "fire.h"
#include "rapidfire.h"
#include "famistudio.h"

#include "render_utils.h"

#include "scene.h"
#include "scene_title.h"
#include "scene_mainmenu.h"
#include "scene_game.h"

extern unsigned char current_game_state;


unsigned char i, j;
unsigned char x, y;
unsigned char nametable;


extern unsigned char music_data_untitled[];


void main(void)
{
    render_disable();

    famistudio_init(FAMISTUDIO_PLATFORM_NTSC, music_data_untitled);

    // Начальная сцена - экран заставки
    current_scene.start_scene = scene_title.start_scene;
    current_scene.render_scene = scene_title.render_scene;
    current_scene.end_scene = scene_title.end_scene;

    current_scene.start_scene();

    while (1)
    {
        current_scene.render_scene();
    }
}
