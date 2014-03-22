/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPL
 *
 * Copyright 2010-2013 by Michael Kohn
 *
 */

#ifndef _TABLE_AVR8_H
#define _TABLE_AVR8_H

#include "assembler.h"

enum
{
  OP_NONE,
  OP_BRANCH_S_K,
  OP_BRANCH_K,
  OP_TWO_REG,
  OP_REG_IMM,
  OP_ONE_REG,
  OP_REG_BIT,
  OP_REG_IMM_WORD,
  OP_IOREG_BIT,
  OP_SREG_BIT,
  OP_REG_4,
  OP_IN,
  OP_OUT,
  OP_MOVW,
  OP_RELATIVE,
  OP_JUMP,
  OP_SPM_Z_PLUS,
  OP_REG_X,
  OP_REG_Y,
  OP_REG_Z,
  OP_REG_X_PLUS,
  OP_REG_Y_PLUS,
  OP_REG_Z_PLUS,
  OP_REG_MINUS_X,
  OP_REG_MINUS_Y,
  OP_REG_MINUS_Z,
  OP_X_REG,
  OP_Y_REG,
  OP_Z_REG,
  OP_X_PLUS_REG,
  OP_Y_PLUS_REG,
  OP_Z_PLUS_REG,
  OP_MINUS_X_REG,
  OP_MINUS_Y_REG,
  OP_MINUS_Z_REG,
  OP_FMUL,
  OP_MUL,
  OP_MULS,
  OP_DATA4,
  OP_REG_SRAM,
  OP_SRAM_REG,
  OP_REG_Y_PLUS_Q,
  OP_REG_Z_PLUS_Q,
  OP_Y_PLUS_Q_REG,
  OP_Z_PLUS_Q_REG,
};

struct _table_avr8
{
  char *instr;
  uint16_t opcode;
  uint16_t mask;
  uint8_t type;
  char cycles_min;
  char cycles_max;
};

extern struct _table_avr8 table_avr8[];

#endif


