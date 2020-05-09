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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disasm/tms340.h"
#include "table/tms340.h"

int get_cycle_count_tms340(unsigned short int opcode)
{
  return -1;
}

static void get_register(char *s, int n, char r)
{
  if (n == 15)
  {
    strcpy(s, "sp");
  }
    else
  {
    sprintf(s, "%c%d", r, n);
  }
}

int disasm_tms340(struct _memory *memory, uint32_t address, char *instruction, int *cycles_min, int *cycles_max)
{
  char operand[32];
  char reg[8];
  uint32_t start = address;
  uint32_t ilw;
  int16_t displacement;
  int16_t mask;
  int opcode;
  int n, i, j, x;
  char r;
  int rs, rd;

  *cycles_min = -1;
  *cycles_max = -1;

  opcode = memory_read16_m(memory, address);

  address += 2;

  r = (opcode & 0x0010) == 0 ? 'a' : 'b';
  rs = (opcode >> 5) & 0xf;
  rd = opcode & 0xf;

  for (n = 0; table_tms340[n].instr != NULL; n++)
  {
    if ((opcode & table_tms340[n].mask) == table_tms340[n].opcode)
    {
      sprintf(instruction, "%s", table_tms340[n].instr);

      for (i = 0; i < table_tms340[n].operand_count; i++)
      {
        if (i == 0)
        {
          strcat(instruction, " ");
        }
          else
        {
          strcat(instruction, ", ");
        }

        switch (table_tms340[n].operand_types[i])
        {
          case OP_RS:
            get_register(reg, rs, r);
            strcat(instruction, reg);
            break;
          case OP_RD:
            get_register(reg, rd, r);
            strcat(instruction, reg);
            break;
          case OP_P_RS:
            get_register(reg, rs, r);
            strcat(instruction, "*");
            strcat(instruction, reg);
            break;
          case OP_P_RD:
            get_register(reg, rd, r);
            strcat(instruction, "*");
            strcat(instruction, reg);
            break;
          case OP_P_RS_DISP:
            get_register(reg, rs, r);
            displacement = memory_read16_m(memory, address);
            sprintf(operand, "*%s(%d)", reg, displacement);
            strcat(instruction, operand);
            address += 2;
            break;
          case OP_P_RD_DISP:
            get_register(reg, rd, r);
            displacement = memory_read16_m(memory, address);
            sprintf(operand, "*%s(%d)", reg, displacement);
            strcat(instruction, operand);
            address += 2;
            break;
          case OP_P_RS_P:
            get_register(reg, rs, r);
            sprintf(operand, "*%s+", reg);
            strcat(instruction, operand);
            break;
          case OP_P_RD_P:
            get_register(reg, rd, r);
            sprintf(operand, "*%s+", reg);
            strcat(instruction, operand);
            break;
          case OP_P_RS_XY:
            get_register(reg, rs, r);
            sprintf(operand, "*%s.XY", reg);
            strcat(instruction, operand);
            break;
          case OP_P_RD_XY:
            get_register(reg, rd, r);
            sprintf(operand, "*%s.XY", reg);
            strcat(instruction, operand);
            break;
          case OP_MP_RS:
            get_register(reg, rs, r);
            sprintf(operand, "-*%s", reg);
            strcat(instruction, operand);
            break;
          case OP_MP_RD:
            get_register(reg, rd, r);
            sprintf(operand, "-*%s", reg);
            strcat(instruction, operand);
            break;
          case OP_ADDRESS:
            break;
          case OP_AT_ADDR:
            ilw = memory_read16_m(memory, address);
            ilw |= memory_read16_m(memory, address + 2) << 16;
            sprintf(operand, "@0x%08x", ilw);
            strcat(instruction, operand);
            address += 4;
            break;
          case OP_LIST:
            mask = memory_read16_m(memory, address);
            x = 0;

            if (mask == 0)
            {
              strcat(instruction, "0");
              break;
            }

            for (j = 0; j < 16; j++)
            {
              if ((mask & (1 << j)) != 0)
              {
                if (x != 0) { strcat(instruction, ", "); }
                get_register(reg, j, r);
                strcat(instruction, reg);
                x++;
              }
            }

            break;
          case OP_B:
          case OP_F:
            strcat(instruction, (opcode & 0x0200) == 0 ? "0" : "1");
            break;
          case OP_K:
          case OP_L:
          case OP_N:
            break;
          case OP_Z:
            strcat(instruction, (opcode & 0x0080) == 0 ? "0" : "1");
            break;
          case OP_FE:
          case OP_FS:
          case OP_IL:
          case OP_IW:
          case OP_NN:
            break;
          case OP_XY:
            strcat(instruction, "XY");
            break;
        }
      }

      return address - start;
    }
  }

  sprintf(instruction, "???");

  return address - start;
}

void list_output_tms340(struct _asm_context *asm_context, uint32_t start, uint32_t end)
{
  int cycles_min,cycles_max;
  char instruction[128];
  int count;
  int n;
  uint32_t opcode;

  while (start < end)
  {
    opcode = (memory_read_m(&asm_context->memory, start) << 8) |
              memory_read_m(&asm_context->memory, start + 1);

    count = disasm_tms340(&asm_context->memory, start, instruction, &cycles_min, &cycles_max);

    fprintf(asm_context->list, "0x%04x: %04x %-40s cycles: ", start, opcode, instruction);

#if 0
    if (cycles_min == cycles_max)
    {
      fprintf(asm_context->list, "%d\n", cycles_min);
    }
      else
    {
      fprintf(asm_context->list, "%d-%d\n", cycles_min, cycles_max);
    }
#endif

    for (n = 2; n < count; n = n + 2)
    {
      opcode = (memory_read_m(&asm_context->memory, start + n) << 8) | memory_read_m(&asm_context->memory, start + n + 1);

      fprintf(asm_context->list, "0x%04x: %04x\n", start + n, opcode);
    }

    start += count;
  }

  fprintf(asm_context->list, "\n");
}

void disasm_range_tms340(struct _memory *memory, uint32_t flags, uint32_t start, uint32_t end)
{
  char instruction[128];
  char bytes[10];
  int cycles_min = 0,cycles_max = 0;
  int count;
  int n;

  printf("\n");

  printf("%-7s %-5s %-40s Cycles\n", "Addr", "Opcode", "Instruction");
  printf("------- ------ ----------------------------------       ------\n");

  while (start <= end)
  {
    count = disasm_tms340(memory, start, instruction, &cycles_min, &cycles_max);

    bytes[0] = 0;

    for (n = 0; n < count; n++)
    {
      char temp[8];
      sprintf(temp, "%04x ", memory_read16_m(memory, start + n));
      strcat(bytes, temp);
    }

    if (cycles_min < 1)
    {
      printf("0x%04x: %-9s %-40s ?\n", start, bytes, instruction);
    }
      else
    if (cycles_min == cycles_max)
    {
      printf("0x%04x: %-9s %-40s %d\n", start, bytes, instruction, cycles_min);
    }
      else
    {
      printf("0x%04x: %-9s %-40s %d-%d\n", start, bytes, instruction, cycles_min, cycles_max);
    }

    start = start + count;
  }
}
