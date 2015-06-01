//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine 
//  Copyright (C) 2015 Dardalorth / Fremos / Carlio
//  Copyright (C) 2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include <types.h>

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////
/////////// PALETTE AND SPRITE DEFINITIONS
///////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// Selected firmware colors from the video palette to be used with the sprite
const u8 G_palette[16] = {
   0x0B, 0x0F, 0x03, 0x18, 0x0D, 0x14, 0x06, 0x1A,
   0x00, 0x02, 0x01, 0x12, 0x08, 0x05, 0x10, 0x09
};

// EMR-Right Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRright[4*16] = {
   0x00,0x0C,0x08,0x00,
   0x00,0x1D,0x2A,0x00,
   0x00,0x1D,0x2A,0x00,
   0x00,0x3F,0x00,0x00,
   0x00,0x30,0xA8,0x00,
   0x10,0x30,0x7E,0x00,
   0x3A,0xBD,0x3F,0x3F,
   0x3F,0xFC,0x3F,0x3F,
   0x3F,0xFF,0xAA,0x00,
   0x3F,0xC4,0x7D,0x00,
   0x00,0x6C,0x7D,0xAA,
   0x14,0x9C,0xFF,0xAA,
   0x6C,0x28,0x44,0xAA,
   0x9C,0x00,0x14,0xAA,
   0xFC,0x00,0x54,0xA8,
   0xFC,0xA8,0x54,0xFC

};

// EMR-Right2 Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRright2[2*16] = {
   0x0C,0x08,
   0x1D,0x2A,
   0x1D,0x2A,
   0x3F,0x00,
   0x30,0xA8,
   0x30,0xFC,
   0x30,0xFC,
   0x3F,0xA8,
   0x3F,0xAA,
   0x3F,0x28,
   0x3F,0x28,
   0x9C,0x28,
   0x9C,0x00,
   0x9C,0x00,
   0xFC,0x00,
   0xFC,0xA8
};

// EMR-Right3 Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRright3[4*16] = {
   0x00,0x0C,0x08,0x00,
   0x00,0x1D,0x2A,0x00,
   0x00,0x1D,0x2A,0x00,
   0x00,0x3F,0x00,0x00,
   0x00,0x30,0xA8,0x00,
   0x10,0x30,0xFC,0x00,
   0x3F,0x74,0xFC,0x3F,
   0x3F,0xFC,0xBD,0x3F,
   0x3F,0xFF,0xAA,0x00,
   0x3F,0x6C,0x3C,0x00,
   0x00,0x3C,0x9C,0x28,
   0x55,0xBE,0x6C,0x28,
   0xDD,0xAA,0x14,0x88,
   0x7D,0x00,0x14,0x88,
   0xFC,0x00,0x54,0xA8,
   0xFC,0xA8,0x54,0xFC
};

// EMR-Left Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRleft[4*16] = {
   0x00,0x04,0x0C,0x00,
   0x00,0x15,0x2E,0x00,
   0x00,0x15,0x2E,0x00,
   0x00,0x00,0x3F,0x00,
   0x00,0x54,0x30,0x00,
   0x00,0xBD,0x30,0x20,
   0x3F,0x3F,0x7E,0x35,
   0x3F,0x3F,0xFC,0x3F,
   0x00,0x55,0xFF,0x3F,
   0x00,0xBE,0x9C,0x3F,
   0x55,0xBE,0x9C,0x00,
   0x55,0xFF,0x6C,0x28,
   0x55,0x88,0x14,0x9C,
   0x55,0x28,0x00,0x6C,
   0x54,0xA8,0x00,0xFC,
   0xFC,0xA8,0x54,0xFC
};

// EMR-Left2 Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRleft2[2*16] = {
   0x04,0x0C,
   0x15,0x2E,
   0x15,0x2E,
   0x00,0x3F,
   0x54,0x30,
   0xFC,0x30,
   0xFC,0x30,
   0x54,0x3F,
   0x55,0x3F,
   0x14,0x3F,
   0x14,0x3F,
   0x14,0x6C,
   0x00,0x6C,
   0x00,0x6C,
   0x00,0xFC,
   0x54,0xFC
};

// EMR-Left3 Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRleft3[4*16] = {
   0x00,0x04,0x0C,0x00,
   0x00,0x15,0x2E,0x00,
   0x00,0x15,0x2E,0x00,
   0x00,0x00,0x3F,0x00,
   0x00,0x54,0x30,0x00,
   0x00,0xFC,0x30,0x20,
   0x3F,0xFC,0xB8,0x3F,
   0x3F,0x7E,0xFC,0x3F,
   0x00,0x55,0xFF,0x3F,
   0x00,0x3C,0x9C,0x3F,
   0x14,0x6C,0x3C,0x00,
   0x14,0x9C,0x7D,0xAA,
   0x44,0x28,0x55,0xEE,
   0x44,0x28,0x00,0xBE,
   0x54,0xA8,0x00,0xFC,
   0xFC,0xA8,0x54,0xFC
};

// EMR-jump-right1 Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRjumpright1[4*8] = {
   0x00,0x00,0x2E,0x0C,
   0x00,0x15,0x3F,0x2E,
   0x00,0x30,0xBD,0x2E,
   0x00,0x30,0x7E,0x00,
   0x00,0xBD,0x3F,0x3F,
   0xFC,0xCC,0x3F,0x3F,
   0xFC,0x3C,0x3C,0x7D,
   0xA8,0x55,0xFF,0xAA
};

// EMR-jump-right2 Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRjumpright2[4*8] = {
   0xFC,0xA8,0x00,0x00,
   0x54,0xA8,0x00,0x00,
   0x14,0xDC,0x30,0x00,
   0xBE,0x9D,0x30,0x2A,
   0xBE,0x3F,0x7E,0x3F,
   0xBE,0x3F,0xBD,0x2E,
   0xBE,0x3F,0x15,0x2E,
   0x55,0x3F,0x04,0x0C
};

// EMR-jump-right3 Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRjumpright3[4*8] = {
   0x55,0xFF,0xAA,0x54,
   0xBE,0x3C,0x3C,0xFC,
   0x3F,0x3F,0xCC,0xFC,
   0x3F,0x3F,0x7E,0x00,
   0x00,0xBD,0x30,0x00,
   0x1D,0x7E,0x30,0x00,
   0x1D,0x3F,0x2A,0x00,
   0x0C,0x1D,0x00,0x00
};

// EMR-jump-right4 Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRjumpright4[4*8] = {
   0x0C,0x08,0x3F,0xAA,
   0x1D,0x2A,0x3F,0x7D,
   0x1D,0x7E,0x3F,0x7D,
   0x3F,0xBD,0x3F,0x7D,
   0x15,0x30,0x6E,0x7D,
   0x00,0x30,0xEC,0x7D,
   0x00,0x00,0x54,0xA8,
   0x00,0x00,0x54,0xFC
};

// EMR-jump-left1 Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRjumpleft1[4*8] = {
   0x0C,0x1D,0x00,0x00,
   0x1D,0x3F,0x2A,0x00,
   0x1D,0x7E,0x30,0x00,
   0x00,0xBD,0x30,0x00,
   0x3F,0x3F,0x7E,0x00,
   0x3F,0x3F,0xCC,0xFC,
   0xBE,0x3C,0x3C,0xFC,
   0x55,0xFF,0xAA,0x54
};

// EMR-jump-left2 Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRjumpleft2[4*8] = {
   0x00,0x00,0x54,0xFC,
   0x00,0x00,0x54,0xA8,
   0x00,0x30,0xEC,0x28,
   0x15,0x30,0x6E,0x7D,
   0x3F,0xBD,0x3F,0x7D,
   0x1D,0x7E,0x3F,0x7D,
   0x1D,0x2A,0x3F,0x7D,
   0x0C,0x08,0x3F,0xAA
};

// EMR-jump-left3 Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRjumpleft3[4*8] = {
   0xA8,0x55,0xFF,0xAA,
   0xFC,0x3C,0x3C,0x7D,
   0xFC,0xCC,0x3F,0x3F,
   0x00,0xBD,0x3F,0x3F,
   0x00,0x30,0x7E,0x00,
   0x00,0x30,0xBD,0x2E,
   0x00,0x15,0x3F,0x2E,
   0x00,0x00,0x2E,0x0C
};

// EMR-jump-left4 Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRjumpleft4[4*8] = {
   0x55,0x3F,0x04,0x0C,
   0xBE,0x3F,0x15,0x2E,
   0xBE,0x3F,0xBD,0x2E,
   0xBE,0x3F,0x7E,0x3F,
   0xBE,0x9D,0x30,0x2A,
   0xBE,0xDC,0x30,0x00,
   0x54,0xA8,0x00,0x00,
   0xFC,0xA8,0x00,0x00
};

// EMR-hitRight Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRhitright[4*16] = {
   0x00,0x00,0x28,0x00,
   0x1D,0x2A,0x00,0x28,
   0x1D,0x3F,0x00,0x00,
   0x0C,0x1D,0x2A,0x28,
   0x00,0x30,0xA8,0x00,
   0x10,0x30,0xFC,0x14,
   0x3A,0xFC,0xFC,0x00,
   0x3F,0xFC,0xA8,0x14,
   0x3F,0xFF,0xAA,0x00,
   0x3F,0x6C,0x7D,0x00,
   0x00,0x6C,0x7D,0xAA,
   0x14,0x9C,0xFF,0xAA,
   0x6C,0x28,0x44,0xAA,
   0x9C,0x00,0x14,0xAA,
   0xFC,0x00,0x54,0xA8,
   0xFC,0xA8,0x54,0xFC
};

// EMR-hitLeft Sprite by Dardalorth / Fremos / Carlio
const u8 G_EMRhitleft[4*16] = {
   0x00,0x14,0x00,0x00,
   0x14,0x00,0x15,0x2E,
   0x00,0x00,0x3F,0x2E,
   0x14,0x15,0x2E,0x0C,
   0x00,0x54,0x30,0x00,
   0x28,0xFC,0x30,0x20,
   0x00,0xFC,0xFC,0x35,
   0x28,0x54,0xFC,0x3F,
   0x00,0x55,0xFF,0x3F,
   0x00,0xBE,0x9C,0x3F,
   0x55,0xBE,0x9C,0x00,
   0x55,0xFF,0x6C,0x28,
   0x55,0x88,0x14,0x9C,
   0x55,0x28,0x00,0x6C,
   0x54,0xA8,0x00,0xFC,
   0xFC,0xA8,0x54,0xFC
};
