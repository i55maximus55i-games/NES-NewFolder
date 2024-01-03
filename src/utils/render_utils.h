#ifndef _RENDER_UTILS_H_
#define _RENDER_UTILS_H_

#define ADDR_NAMETABLE_A PPU_ADDR = 0x20; PPU_ADDR = 0x00;
#define ADDR_NAMETABLE_B PPU_ADDR = 0x24; PPU_ADDR = 0x00;
#define ADDR_NAMETABLE_C PPU_ADDR = 0x28; PPU_ADDR = 0x00;
#define ADDR_NAMETABLE_D PPU_ADDR = 0x2C; PPU_ADDR = 0x00;

extern unsigned char x, y, i;

void render_disable(void)
{
    PPU_MASK = MASK_HIDE_BG | MASK_HIDE_SPRITE;
    PPU_CTRL = CTRL_NAMETABLE_2000 | CTRL_INCREMENT_1 | CTRL_SPRITE_1000 | CTRL_BG_0000 | CTRL_SPRITE_8x8 | CTRL_NMI_DISABLE;
}

void fill_nametable(unsigned char nametable, unsigned char value)
{
    switch (nametable)
    {
        case 0: ADDR_NAMETABLE_A; break;
        case 1: ADDR_NAMETABLE_B; break;
        case 2: ADDR_NAMETABLE_C; break;
        case 3: ADDR_NAMETABLE_D; break;
    }
    for (y = 0; y < 30; ++y)
    {
        for (x = 0; x < 32; ++x)
        {
            PPU_DATA = value;
        }
    }
}

void pallete_set_background(unsigned char color)
{
    PPU_ADDR = 0x3F; PPU_ADDR = 0x00;
    PPU_DATA = color;
}

void pallete_set_background_pallete(unsigned char pallete_number, unsigned char color_0, unsigned char color_1, unsigned char color_2)
{
    PPU_ADDR = 0x3F; PPU_ADDR = 0x01 + pallete_number * 4;
    PPU_DATA = color_0;
    PPU_DATA = color_1;
    PPU_DATA = color_2;
}

void pallete_set_sprite_pallete(unsigned char pallete_number, unsigned char color_0, unsigned char color_1, unsigned char color_2)
{
    PPU_ADDR = 0x3F; PPU_ADDR = 0x11 + pallete_number * 4;
    PPU_DATA = color_0;
    PPU_DATA = color_1;
    PPU_DATA = color_2;
}

void print_string(char* str)
{
    for (i = 0; str[i] != '\\'; ++i) PPU_DATA = str[i];
}

#endif