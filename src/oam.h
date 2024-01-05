#ifndef _OAM_H_
#define _OAM_H_


extern char nmi_oam_enable;
#pragma zpsym ("nmi_oam_enable");

typedef struct {
    unsigned char y;
    unsigned char tile_index;
    unsigned char attributes;
    unsigned char x;
} sprite_t;
extern sprite_t oam_shadow[];


#endif