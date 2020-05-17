/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPLv3
 *
 * Copyright 2010-2020 by Michael Kohn
 *
 */

#include "table/tms340.h"

struct _table_tms340 table_tms340[] =
{
  { "addxy",  0xe000, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "cmpxy",  0xe400, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "cpw",    0xe600, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "cvxyl",  0xe800, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "drav",   0xf600, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "fill",   0x0fc0, 0xffff, 1, { OP_L,         OP_NONE,      OP_NONE }},
  { "fill",   0x0fe0, 0xffff, 1, { OP_XY,        OP_NONE,      OP_NONE }},
  { "movx",   0xec00, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "movy",   0xee00, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "pixblt", 0x0f80, 0xffff, 2, { OP_B,         OP_L,         OP_NONE }},
  { "pixblt", 0x0fa0, 0xffff, 2, { OP_B,         OP_XY,        OP_NONE }},
  { "pixblt", 0x0f00, 0xffff, 2, { OP_L,         OP_L,         OP_NONE }},
  { "pixblt", 0x0f20, 0xffff, 2, { OP_L,         OP_XY,        OP_NONE }},
  { "pixblt", 0x0f40, 0xffff, 2, { OP_XY,        OP_L,         OP_NONE }},
  { "pixblt", 0x0f60, 0xffff, 2, { OP_XY,        OP_XY,        OP_NONE }},
  { "pixt",   0xf800, 0xfe00, 2, { OP_RS,        OP_P_RD,      OP_NONE }},
  { "pixt",   0xf000, 0xfe00, 2, { OP_RS,        OP_P_RD_XY,   OP_NONE }},
  { "pixt",   0xfa00, 0xfe00, 2, { OP_P_RS,      OP_RD,        OP_NONE }},
  { "pixt",   0xfc00, 0xfe00, 2, { OP_P_RS,      OP_P_RD,      OP_NONE }},
  { "pixt",   0xf200, 0xfe00, 2, { OP_P_RS_XY,   OP_RD,        OP_NONE }},
  { "pixt",   0xf400, 0xfe00, 2, { OP_P_RS_XY,   OP_P_RD_XY,   OP_NONE }},
  { "subxy",  0xe200, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "line",   0xdf1a, 0xff7f, 1, { OP_Z,         OP_NONE,      OP_NONE }},
  { "movb",   0x8c00, 0xfe00, 2, { OP_RS,        OP_P_RD,      OP_NONE }},
  { "movb",   0x8e00, 0xfe00, 2, { OP_P_RS,      OP_RD,        OP_NONE }},
  { "movb",   0x9c00, 0xfe00, 2, { OP_P_RS,      OP_P_RD,      OP_NONE }},
  { "movb",   0xac00, 0xfe00, 2, { OP_RS,        OP_P_RD_DISP, OP_NONE }},
  { "movb",   0xae00, 0xfe00, 2, { OP_P_RS_DISP, OP_RD,        OP_NONE }},
  { "movb",   0xbc00, 0xfe00, 2, { OP_P_RS_DISP, OP_P_RD_DISP, OP_NONE }},
  { "movb",   0x05e0, 0xffe0, 2, { OP_RD,        OP_AT_ADDR,   OP_NONE }},
  { "movb",   0x07e0, 0xffe0, 2, { OP_AT_ADDR,   OP_RD,        OP_NONE }},
  { "movb",   0x0340, 0xffff, 2, { OP_AT_ADDR,   OP_AT_ADDR,   OP_NONE }},
  { "move",   0x4c00, 0xfc00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "move",   0x8000, 0xfc00, 3, { OP_RS,        OP_P_RD,      OP_F }},
  { "move",   0xa000, 0xfc00, 3, { OP_RS,        OP_MP_RD,     OP_F }},
  { "move",   0x9000, 0xfc00, 3, { OP_RS,        OP_P_RD_P,    OP_F }},
  { "move",   0x8400, 0xfc00, 3, { OP_P_RS,      OP_RD,        OP_F }},
  { "move",   0xa400, 0xfc00, 3, { OP_MP_RS,     OP_RD,        OP_F }},
  { "move",   0x9400, 0xfc00, 3, { OP_P_RS_P,    OP_RD,        OP_F }},
  { "move",   0x8800, 0xfc00, 3, { OP_P_RS,      OP_P_RD,      OP_F }},
  { "move",   0xa800, 0xfc00, 3, { OP_MP_RS,     OP_MP_RD,     OP_F }},
  { "move",   0x9800, 0xfc00, 3, { OP_P_RS_P,    OP_P_RD_P,    OP_F }},
  { "move",   0xb000, 0xfc00, 3, { OP_RS,        OP_P_RD_DISP, OP_F }},
  { "move",   0xb400, 0xfc00, 3, { OP_P_RS_DISP, OP_RD,        OP_F }},
  { "move",   0xd000, 0xfc00, 3, { OP_P_RS_DISP, OP_P_RD_P,    OP_F }},
  { "move",   0xb800, 0xfc00, 3, { OP_P_RS_DISP, OP_P_RD_DISP, OP_F }},
  { "move",   0x0580, 0xfde0, 3, { OP_RD,        OP_AT_ADDR,   OP_F }},
  { "move",   0x05a0, 0xfde0, 3, { OP_AT_ADDR,   OP_RD,        OP_F }},
  { "move",   0xd400, 0xfde0, 3, { OP_AT_ADDR,   OP_P_RD_P,    OP_F }},
  { "move",   0x05c0, 0xfdf0, 3, { OP_AT_ADDR,   OP_AT_ADDR,   OP_F }},
  { "abs",    0x0380, 0xffe0, 1, { OP_RD,        OP_NONE,      OP_NONE }},
  { "add",    0x4000, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "addc",   0x4200, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "addi",   0x0b00, 0xffe0, 2, { OP_IW,        OP_RD,        OP_NONE }},
  { "addi",   0x0b20, 0xffe0, 2, { OP_IL,        OP_RD,        OP_NONE }},
  { "addk",   0x1000, 0xfc00, 2, { OP_K32,       OP_RD,        OP_NONE }},
  { "and",    0x5000, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "andi",   0x0b80, 0xffe0, 2, { OP_NIL,       OP_RD,        OP_NONE }},
  { "andn",   0x5200, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "andni",  0x0b80, 0xffe0, 2, { OP_IL,        OP_RD,        OP_NONE }},
  { "btst",   0x1c00, 0xfc00, 2, { OP_1K,        OP_RD,        OP_NONE }},
  { "btst",   0x4a00, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "clr",    0x5600, 0xfe00, 1, { OP_RDS,       OP_NONE,      OP_NONE }},
  { "clrc",   0x0320, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "cmp",    0x4840, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "cmpi",   0x0b40, 0xffe0, 2, { OP_NIW,       OP_RD,        OP_NONE }},
  { "cmpi",   0x0b60, 0xffe0, 2, { OP_NIL,       OP_RD,        OP_NONE }},
  { "dec",    0x1420, 0xffe0, 1, { OP_RD,        OP_NONE,      OP_NONE }},
  { "dint",   0x0360, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "divs",   0x5800, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "divu",   0x5a00, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "eint",   0x0d60, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "exgf",   0xd500, 0xfde0, 2, { OP_RD,        OP_F,         OP_NONE }},
  { "lmo",    0x6a00, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "mmfm",   0x09a0, 0xffe0, 2, { OP_RD,        OP_LIST,      OP_NONE }},
  { "mmtm",   0x0980, 0xffe0, 2, { OP_RD,        OP_LIST,      OP_NONE }},
  { "mods",   0x6c00, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "modu",   0x6e00, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "movi",   0x09c0, 0xffe0, 2, { OP_IW,        OP_RD,        OP_NONE }},
  { "movi",   0x09e0, 0xffe0, 2, { OP_IL,        OP_RD,        OP_NONE }},
  { "movk",   0x1800, 0xfc00, 2, { OP_K32,       OP_RD,        OP_NONE }},
  { "mpys",   0x5c00, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "mpyu",   0x5e00, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "neg",    0x03a0, 0xffe0, 1, { OP_RD,        OP_NONE,      OP_NONE }},
  { "negb",   0x03c0, 0xffe0, 1, { OP_RD,        OP_NONE,      OP_NONE }},
  { "nop",    0x0300, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "not",    0x03e0, 0xffe0, 1, { OP_RD,        OP_NONE,      OP_NONE }},
  { "or",     0x5400, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "ori",    0x0ba0, 0xffe0, 2, { OP_IL,        OP_RD,        OP_NONE }},
  { "rl",     0x3000, 0xfc00, 2, { OP_K,         OP_RD,        OP_NONE }},
  { "rl",     0x6800, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "setc",   0x0de0, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "setf",   0x0540, 0xfdc0, 3, { OP_FS,        OP_FE,        OP_F }},
  { "sext",   0x0500, 0xfde0, 2, { OP_RD,        OP_F,         OP_NONE }},
  { "sla",    0x2000, 0xfc00, 2, { OP_K,         OP_RD,        OP_NONE }},
  { "sla",    0x6000, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "sll",    0x2400, 0xfc00, 2, { OP_K,         OP_RD,        OP_NONE }},
  { "sll",    0x6200, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "sra",    0x2800, 0xfc00, 2, { OP_2K,        OP_RD,        OP_NONE }},
  { "sra",    0x6400, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "srl",    0x2c00, 0xfc00, 2, { OP_2K,        OP_RD,        OP_NONE }},
  { "srl",    0x6600, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "sub",    0x4400, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "subb",   0x4600, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "subi",   0x0be0, 0xffe0, 2, { OP_NIW,       OP_RD,        OP_NONE }},
  { "subi",   0x0d00, 0xffe0, 2, { OP_NIL,       OP_RD,        OP_NONE }},
  { "subk",   0x1400, 0xfc00, 2, { OP_K32,       OP_RD,        OP_NONE }},
  { "xor",    0x5600, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "xori",   0x0bc0, 0xffe0, 2, { OP_IL,        OP_RD,        OP_NONE }},
  { "zext",   0x0520, 0xfde0, 2, { OP_RD,        OP_F,         OP_NONE }},
  { "call",   0x0920, 0xffe0, 1, { OP_RD,        OP_NONE,      OP_NONE }},
  { "calla",  0x0d5f, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "callr",  0x0d3f, 0xffff, 1, { OP_DISP,      OP_NONE,      OP_NONE }},
  { "dsj",    0x0d80, 0xffe0, 2, { OP_RD,        OP_DISP,      OP_NONE }},
  { "dsjeq",  0x0da0, 0xffe0, 2, { OP_RD,        OP_DISP,      OP_NONE }},
  { "dsjne",  0x0dc0, 0xffc0, 2, { OP_RD,        OP_DISP,      OP_NONE }},
  { "dsjs",   0x3800, 0xf800, 2, { OP_RD,        OP_SKIP,      OP_NONE }},
  { "emu",    0x0100, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "exgpc",  0x0120, 0xffe0, 1, { OP_RD,        OP_NONE,      OP_NONE }},
  { "getpc",  0x0140, 0xffe0, 1, { OP_RD,        OP_NONE,      OP_NONE }},
  { "getst",  0x0180, 0xffe0, 1, { OP_RD,        OP_NONE,      OP_NONE }},
  { "jauc",   0xc080, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jap",    0xc180, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jals",   0xc280, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jahi",   0xc380, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jalt",   0xc480, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jage",   0xc580, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jale",   0xc680, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jagt",   0xc780, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jac",    0xc880, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jalo",   0xc880, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jab",    0xc880, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "janc",   0xc980, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jahs",   0xc980, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "janb",   0xc980, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jaz",    0xca80, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jaeq",   0xca80, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "janz",   0xcb80, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jane",   0xcb80, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jav",    0xcc80, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "janv",   0xcd80, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jan",    0xce80, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jann",   0xcf80, 0xffff, 1, { OP_ADDRESS,   OP_NONE,      OP_NONE }},
  { "jruc",   0xc000, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrp",    0xc100, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrls",   0xc200, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrhi",   0xc300, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrlt",   0xc400, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrge",   0xc500, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrle",   0xc600, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrgt",   0xc700, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrc",    0xc800, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrb",    0xc800, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrlo",   0xc800, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrnc",   0xc900, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrhs",   0xc900, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrnb",   0xc900, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrz",    0xca00, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jreq",   0xca00, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrnz",   0xcb00, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrne",   0xcb00, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrv",    0xcc00, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrnv",   0xcd00, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrn",    0xce00, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jrnn",   0xcf00, 0xff00, 1, { OP_JUMP_REL,  OP_NONE,      OP_NONE }},
  { "jump",   0x0160, 0xffe0, 1, { OP_RD,        OP_NONE,      OP_NONE }},
  { "popst",  0x01c0, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "pushst", 0x01e0, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "putst",  0x01a0, 0xffe0, 1, { OP_RS,        OP_NONE,      OP_NONE }},
  { "reti",   0x0940, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "rets",   0x0960, 0xffe0, 1, { OP_NN,        OP_NONE,      OP_NONE }},
  { "trap",   0x0900, 0xffe0, 1, { OP_N,         OP_NONE,      OP_NONE }},
  // TMS34020
  { "fpixeq", 0x0abb, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "fpixne", 0x0adb, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "idle",   0x0040, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "setcdp", 0x0273, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "setcmp", 0x02fb, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "setcsp", 0x0251, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "retm",   0x0860, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "rev",    0x0020, 0xffe0, 1, { OP_RD,        OP_NONE,      OP_NONE }},
  { "rmo",    0x7a00, 0xfe00, 2, { OP_RS,        OP_RD,        OP_NONE }},
  { "rpix",   0x0280, 0xffe0, 1, { OP_RD,        OP_NONE,      OP_NONE }},
  { "trapl",  0x080f, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "vblt",   0x0857, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "vfill",  0x0a5e, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { "vlcol",  0x0a00, 0xffff, 0, { OP_NONE,      OP_NONE,      OP_NONE }},
  { NULL,          0,      0, 0, {    0,               0,            0 }}
};

