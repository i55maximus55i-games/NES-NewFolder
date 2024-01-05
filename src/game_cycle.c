#include "game_cycle.h"

void game_update()
{
    game_player_update();
    game_helicopter_update();
    game_bullet_movement();

    game_update_ppu();
}

void game_update_ppu()
{
    // NAMETABLE

    // OAM
    game_player_oam();
    game_helicopter_oam();
    game_bullet_oam();
    nmi_oam_enable = 0x02;

    // NMI
    wait_for_nmi();
}