#include "fire.h"
#include "rapidfire.h"
#include "famistudio.h"

#include "utils/render_utils.h"
#include "utils/phys_x.h"

#include "scenes/scene.h"
#include "scenes/scene_title.h"
#include "scenes/scene_mainmenu.h"
#include "scenes/scene_game.h"

extern unsigned char current_game_state;


unsigned char i, j;
unsigned char x, y;
unsigned char nametable;


extern unsigned char music_data_untitled[];


void main(void)
{
    render_disable();

    famistudio_init(FAMISTUDIO_PLATFORM_PAL, music_data_untitled);

    // Начальная сцена - экран заставки
    current_scene.start_scene = scene_title.start_scene;
    current_scene.render_scene = scene_title.render_scene;
    current_scene.end_scene = scene_title.end_scene;

    current_scene.start_scene();

    while (1) {
        current_scene.render_scene();
    }
}
