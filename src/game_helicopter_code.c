#include "game_helicopter_code.h"


void game_helicopter_oam()
{
    for (i = 0; i < 5; ++i)
    {
        oam_shadow[54 + i].x = helicopter_1.x + 8 * i;
        oam_shadow[54 + i].y = helicopter_1.y;
        oam_shadow[54 + i].tile_index = 0x56 + 2 * i;
        oam_shadow[54 + i].attributes = 0;
    }
    for (i = 0; i < 5; ++i)
    {
        oam_shadow[59 + i].x = helicopter_1.x + 8 * i;
        oam_shadow[59 + i].y = helicopter_1.y + 16;
        oam_shadow[59 + i].tile_index = 0x76 + 2 * i;
        oam_shadow[59 + i].attributes = 0;
    }
}

void game_helicopter_update()
{
    helicopter_1.timer++;

    switch (helicopter_1.state)
    {
        case HELICOPTER_STATE_ENTRY:
            {
                helicopter_1.x -= 3;
                if (helicopter_1.x < 210)
                {
                    if (helicopter_1.t == 0)
                    {
                        game_helicopter_switch_state(HELICOPTER_STATE_TARAN);
                        helicopter_1.t = 1;
                    }
                    else
                    {
                        game_helicopter_switch_state(HELICOPTER_STATE_BURST_NAHUI);
                        helicopter_1.t = 0;
                    }

                    helicopter_1.x = 210;
                    helicopter_1.y = 60;
                }
            }
            break;
        case HELICOPTER_STATE_TARAN:
            {
                if (helicopter_1.substate == 0)
                {
                    if (helicopter_1.timer > 30)
                    {
                        helicopter_1.timer = 0;
                        helicopter_1.substate = 1;
                    }
                }
                else 
                {
                    helicopter_1.x -= 4;
                    if (helicopter_1.x < 10)
                    {
                        game_helicopter_switch_state(HELICOPTER_STATE_ENTRY);
                    }
                }
            }
            break;
        case HELICOPTER_STATE_BURST_NAHUI:
            {
                helicopter_1.x = 210;
                if (helicopter_1.substate == 0)
                {
                    if (helicopter_1.y > 16)
                    {
                        helicopter_1.y -= 3;
                    }
                    else 
                    {
                        helicopter_1.substate = 1;
                        helicopter_1.timer = 0;
                    }
                }
                else
                {
                    helicopter_1.y++;
                    if (helicopter_1.timer > 3)
                    {
                        game_bullet_spawn(helicopter_1.x - 10, helicopter_1.y + 16, -3, 0);
                        helicopter_1.timer = 0;
                    }
                    if (helicopter_1.y < 8)
                    {
                        game_helicopter_switch_state(HELICOPTER_STATE_ENTRY);
                    }
                }
            }
            break;
    }
}

void game_helicopter_switch_state(unsigned char helicopter_state_next)
{
    if (helicopter_state_next == HELICOPTER_STATE_ENTRY)
    {
        helicopter_1.y = 150;
        helicopter_1.x = 255;
    }

    helicopter_1.state = helicopter_state_next;
    helicopter_1.substate = 0;
    helicopter_1.timer = 0;
}