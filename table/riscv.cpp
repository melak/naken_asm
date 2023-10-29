/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: https://www.mikekohn.net/
 * License: GPLv3
 *
 * Copyright 2010-2023 by Michael Kohn
 *
 */

#include "table/riscv.h"

struct _table_riscv table_riscv[] =
{
  // Alias instructions.
  { "nop",        0x00000013, 0xffffffff, OP_NONE,       0 },
  // mv rd, rs           : addi rd, rs, 0
  // not rd, rs          : xori rd, rs, -1
  // neg rd, rs          : sub rd, x0, rs
  // negw rd, rs         : subw rd, x0, rs
  // sext.w rd, rs       : addiw rd, rs, 0
  // seqz rd, rs         : sltiu rd, rs, 1
  // snez rd, rs         : sltu rd, x0, rs
  // sltz rd, rs         : slt rd, rs, x0
  // sgtz rd, rs         : slt rd, x0, rs
  { "mv",         0x00000013, 0xfff0707f, OP_ALIAS_RD_RS1,       0 },
  { "not",        0xfff00013, 0xfff0707f, OP_ALIAS_RD_RS1,       0 },
  { "neg",        0x40000033, 0xfe0ff07f, OP_ALIAS_RD_RS2,       0 },
  { "negw",       0x4000003b, 0xfe0ff07f, OP_ALIAS_RD_RS2, RISCV64 },
  { "sext.w",     0x0000001b, 0xfff0707f, OP_ALIAS_RD_RS1, RISCV64 },
  { "seqz",       0x00103013, 0x0000707f, OP_ALIAS_RD_RS1,       0 },
  { "snez",       0x00003033, 0xfe0ff07f, OP_ALIAS_RD_RS2,       0 },
  { "sltz",       0x00002033, 0xfff0707f, OP_ALIAS_RD_RS1,       0 },
  { "slgt",       0x00002033, 0xfe0ff07f, OP_ALIAS_RD_RS2,       0 },
  // fmv.s rd rs         : fsgnj.s rd, rs, rs
  // fabs.s rd, rs       : fsgnjx.s rd, rs, rs
  // fneg.s rd, rs       : fsgnjn.s rd, rs, rs
  // fmv.d rd, rs        : fsgnj.d rd, rs, rs
  // fabs.d rd, rs       : fsgnjx.d rd, rs, rs
  // fneg.d rd, rs       : fsgnjn.d rd, rs, rs
  { "fmv.s",      0x20000053, 0xfe00707f, OP_ALIAS_FP_FP,        0 },
  { "fabs.s",     0x20002053, 0xfe00707f, OP_ALIAS_FP_FP,        0 },
  { "fneg.s",     0x20001053, 0xfe00707f, OP_ALIAS_FP_FP,        0 },
  { "fmv.d",      0x22000053, 0xfe00707f, OP_ALIAS_FP_FP,        0 },
  { "fabs.d",     0x22002053, 0xfe00707f, OP_ALIAS_FP_FP,        0 },
  { "fneg.d",     0x22001053, 0xfe00707f, OP_ALIAS_FP_FP,        0 },
  // beqz rs, offset     : beq rs, x0, offset
  // bnez rs, offset     : bne rs, x0, offset
  // blez rs, offset     : bge x0, rs, offset
  // bgez rs, offset     : bge rs, x0, offset
  // bltz rs, offset     : blt rs, x0, offset
  // bgtz rs, offset     : blt x0, rs, offset
  // bgt rs, rt, offset  : blt rt, rs, offset
  // ble rs, rt, offset  : bge rt, rs, offset
  // bgtu rs, rt, offset : bltu rt, rs, offset
  // bleu rs, rt, offset : bgeu rt, rs, offset
  { "beqz",       0x00000063, 0x01f0707f, OP_ALIAS_BR_RS_X0,    0 },
  { "bnez",       0x00001063, 0x01f0707f, OP_ALIAS_BR_RS_X0,    0 },
  { "blez",       0x00005063, 0x01f0707f, OP_ALIAS_BR_X0_RS,    0 },
  { "bgez",       0x00005063, 0x000ff07f, OP_ALIAS_BR_RS_X0,    0 },
  { "bltz",       0x00004063, 0x000ff07f, OP_ALIAS_BR_RS_X0,    0 },
  { "bgtz",       0x00004063, 0x01f0707f, OP_ALIAS_BR_X0_RS,    0 },
  { "bgt",        0x00004063, 0x0000707f, OP_ALIAS_BR_RS_RT,    0 },
  { "ble",        0x00005063, 0x0000707f, OP_ALIAS_BR_RS_RT,    0 },
  { "bgtu",       0x00006063, 0x0000707f, OP_ALIAS_BR_RS_RT,    0 },
  { "bleu",       0x00007063, 0x0000707f, OP_ALIAS_BR_RS_RT,    0 },
  // j offset            : jal x0, offset
  // jal offset          : jal x1, offset
  // jr rs               : jalr x0, rs, 0
  // jalr rs             : jalr x1, rs, 0
  // ret                 : jalr x0, x1, 0
  { "j",          0x0000006f, 0x00000fff, OP_ALIAS_JAL,         0 },
  { "jal",        0x000000ef, 0x00000fff, OP_ALIAS_JAL,         0 },
  { "jr",         0x00000067, 0xfff07fff, OP_ALIAS_JALR,        0 },
  { "jalr",       0x000000e7, 0xfff07fff, OP_ALIAS_JALR,        0 },
  { "ret",        0x00008067, 0xffffffff, OP_NONE,              0 },
  // call offset         : auipc x6, offset[31:12]
  //                       jalr x1, x6, offset[11:0]
  // tail offset         : auipc x6, offset[31:12]
  //                       jalr x0, x6, offset[11:0]
  //{ "call",       0x00000017, 0x0000007f, OP_U_TYPE,            0 },
  //{ "tail",       0x00000017, 0x0000007f, OP_U_TYPE,            0 },
  // fence               : fence iorw, iorw
  { "fence",      0x0000000f, 0xffffffff, OP_NONE,              0 },
  // rdinstret[h] rd     : csrrs rd, instret[h], x0
  // rdcycle[h] rd       : csrrs rd, cycle[h], x0
  // rdtime[h] rd        : csrrs rd, time[h], x0
  // csrr rd, csr        : csrrs rd, csr, x0
  // csrw csr, rs        : csrrw x0, csr, rs
  // csrs csr, rs        : csrrs x0, csr, rs
  // csrc csr, rs        : csrrc x0, csr, rs
  // csrwi csr, imm      : csrrwi x0, csr, imm
  // csrsi csr, imm      : csrrsi x0, csr, imm
  // csrci csr, imm      : csrrci x0, csr, imm
  // frcsr rd            : csrrs rd, fcsr, x0
  // fscsr rd, rs        : csrrw rd, fcsr, rs
  // fscsr rs            : csrrw x0, fcsr, rs
  // frrm rd             : csrrs rd, frm, x0
  // fsrm rd, rs         : csrrw rd, frm, rs
  // fsrm rs             : csrrw x0, frm, rs
  // fsrmi rd, imm       : csrrwi rd, frm, imm
  // fsrmi imm           : csrrwi x0, frm, imm
  // frflags rd          : csrrs rd, fflags, x0
  // fsflags rd, rs      : csrrw rd, fflags, rs
  // fsflags rs          : csrrw x0, fflags, rs
  // fsflagsi rd, imm    : csrrwi rd, fflags, imm
  // fsflagsi imm        : csrrwi x0, fflags, imm
  // Regular instructions.
  { "lui",        0x00000037, 0x0000007f, OP_U_TYPE,     0 },
  { "auipc",      0x00000017, 0x0000007f, OP_U_TYPE,     0 },
  { "jal",        0x0000006f, 0x0000007f, OP_UJ_TYPE,    0 },
  { "jalr",       0x00000067, 0x0000707f, OP_I_TYPE,     0 },
  { "beq",        0x00000063, 0x0000707f, OP_SB_TYPE,    0 },
  { "bne",        0x00001063, 0x0000707f, OP_SB_TYPE,    0 },
  { "blt",        0x00004063, 0x0000707f, OP_SB_TYPE,    0 },
  { "bge",        0x00005063, 0x0000707f, OP_SB_TYPE,    0 },
  { "bltu",       0x00006063, 0x0000707f, OP_SB_TYPE,    0 },
  { "bgeu",       0x00007063, 0x0000707f, OP_SB_TYPE,    0 },
  { "lb",         0x00000003, 0x0000707f, OP_RD_INDEX_R, 0 },
  { "lh",         0x00001003, 0x0000707f, OP_RD_INDEX_R, 0 },
  { "lw",         0x00002003, 0x0000707f, OP_RD_INDEX_R, 0 },
  { "lbu",        0x00004003, 0x0000707f, OP_RD_INDEX_R, 0 },
  { "lhu",        0x00005003, 0x0000707f, OP_RD_INDEX_R, 0 },
  { "sb",         0x00000023, 0x0000707f, OP_RS_INDEX_R, 0 },
  { "sh",         0x00001023, 0x0000707f, OP_RS_INDEX_R, 0 },
  { "sw",         0x00002023, 0x0000707f, OP_RS_INDEX_R, 0 },
  { "addi",       0x00000013, 0x0000707f, OP_I_TYPE,     0 },
  { "slti",       0x00002013, 0x0000707f, OP_I_TYPE,     0 },
  { "sltiu",      0x00003013, 0x0000707f, OP_I_TYPE,     0 },
  { "xori",       0x00004013, 0x0000707f, OP_I_TYPE,     0 },
  { "ori",        0x00006013, 0x0000707f, OP_I_TYPE,     0 },
  { "andi",       0x00007013, 0x0000707f, OP_I_TYPE,     0 },
  { "slli",       0x00001013, 0xfe00707f, OP_SHIFT,      0 },
  { "srli",       0x00005013, 0xfe00707f, OP_SHIFT,      0 },
  { "srai",       0x40005013, 0xfe00707f, OP_SHIFT,      0 },
  { "add",        0x00000033, 0xfe00707f, OP_R_TYPE,     0 },
  { "sub",        0x40000033, 0xfe00707f, OP_R_TYPE,     0 },
  { "sll",        0x00001033, 0xfe00707f, OP_R_TYPE,     0 },
  { "slt",        0x00002033, 0xfe00707f, OP_R_TYPE,     0 },
  { "sltu",       0x00003033, 0xfe00707f, OP_R_TYPE,     0 },
  { "xor",        0x00004033, 0xfe00707f, OP_R_TYPE,     0 },
  { "srl",        0x00005033, 0xfe00707f, OP_R_TYPE,     0 },
  { "sra",        0x40005033, 0xfe00707f, OP_R_TYPE,     0 },
  { "or",         0x00006033, 0xfe00707f, OP_R_TYPE,     0 },
  { "and",        0x00007033, 0xfe00707f, OP_R_TYPE,     0 },
  { "fence",      0x0000000f, 0xf00fffff, OP_FENCE,      0 },
  { "fence.i",    0x0000100f, 0xffffffff, OP_FFFF,       0 },
  { "ecall",      0x00000073, 0xffffffff, OP_FFFF,       0 },
  { "ebreak",     0x00100073, 0xffffffff, OP_FFFF,       0 },
  { "rdcycle",    0xc0002073, 0xfffff07f, OP_READ,       0 },
  { "rdcycleh",   0xc8002073, 0xfffff07f, OP_READ,       0 },
  { "rdtime",     0xc0102073, 0xfffff07f, OP_READ,       0 },
  { "rdtimeh",    0xc8102073, 0xfffff07f, OP_READ,       0 },
  { "rdinstret",  0xc0202073, 0xfffff07f, OP_READ,       0 },
  { "rdinstreth", 0xc8202073, 0xfffff07f, OP_READ,       0 },
  { "lwu",        0x00006003, 0x0000707f, OP_RD_INDEX_R, RISCV64 },
  { "ld",         0x00003003, 0x0000707f, OP_RD_INDEX_R, RISCV64 },
  { "sd",         0x00003023, 0x0000707f, OP_RS_INDEX_R, RISCV64 },
  //{ "slli",       0x00001013, 0xfe00707f, OP_SHIFT,      RISCV64 },
  //{ "srli",       0x00005013, 0xfe00707f, OP_SHIFT,      RISCV64 },
  //{ "srai",       0x40005013, 0xfe00707f, OP_SHIFT,      RISCV64 },
  { "addiw",      0x0000001b, 0x0000707f, OP_I_TYPE,     RISCV64 },
  { "slliw",      0x0000101b, 0xfe00707f, OP_SHIFT,      RISCV64 },
  { "srliw",      0x0000501b, 0xfe00707f, OP_SHIFT,      RISCV64 },
  { "sraiw",      0x4000501b, 0xfe00707f, OP_SHIFT,      RISCV64 },
  { "addw",       0x0000003b, 0xfe00707f, OP_R_TYPE,     RISCV64 },
  { "subw",       0x4000003b, 0xfe00707f, OP_R_TYPE,     RISCV64 },
  { "sllw",       0x0000103b, 0xfe00707f, OP_R_TYPE,     RISCV64 },
  { "srlw",       0x0000503b, 0xfe00707f, OP_R_TYPE,     RISCV64 },
  { "sraw",       0x4000503b, 0xfe00707f, OP_R_TYPE,     RISCV64 },
  { "mul",        0x02000033, 0xfe00707f, OP_R_TYPE,     0 },
  { "mulh",       0x02001033, 0xfe00707f, OP_R_TYPE,     0 },
  { "mulhsu",     0x02002033, 0xfe00707f, OP_R_TYPE,     0 },
  { "mulhu",      0x02003033, 0xfe00707f, OP_R_TYPE,     0 },
  { "div",        0x02004033, 0xfe00707f, OP_R_TYPE,     0 },
  { "divu",       0x02005033, 0xfe00707f, OP_R_TYPE,     0 },
  { "rem",        0x02006033, 0xfe00707f, OP_R_TYPE,     0 },
  { "remu",       0x02007033, 0xfe00707f, OP_R_TYPE,     0 },
  { "mulw",       0x0200003b, 0xfe00707f, OP_R_TYPE,     RISCV64 },
  { "divw",       0x0200403b, 0xfe00707f, OP_R_TYPE,     RISCV64 },
  { "divuw",      0x0200503b, 0xfe00707f, OP_R_TYPE,     RISCV64 },
  { "remw",       0x0200603b, 0xfe00707f, OP_R_TYPE,     RISCV64 },
  { "remuw",      0x0200703b, 0xfe00707f, OP_R_TYPE,     RISCV64 },
  { "lr.w",       0x1000202f, 0xf800707f, OP_LR,         0 },
  { "sc.w",       0x1800202f, 0xf800707f, OP_STD_EXT,    0 },
  { "amoswap.w",  0x0800202f, 0xf800707f, OP_STD_EXT,    0 },
  { "amoadd.w",   0x0000202f, 0xf800707f, OP_STD_EXT,    0 },
  { "amoxor.w",   0x2000202f, 0xf800707f, OP_STD_EXT,    0 },
  { "amoand.w",   0x6000202f, 0xf800707f, OP_STD_EXT,    0 },
  { "amoor.w",    0x4000202f, 0xf800707f, OP_STD_EXT,    0 },
  { "amomin.w",   0x8000202f, 0xf800707f, OP_STD_EXT,    0 },
  { "amomax.w",   0xa000202f, 0xf800707f, OP_STD_EXT,    0 },
  { "amominu.w",  0xc000202f, 0xf800707f, OP_STD_EXT,    0 },
  { "amomaxu.w",  0xe000202f, 0xf800707f, OP_STD_EXT,    0 },
  { "lr.d",       0x1000302f, 0xf800707f, OP_LR,         0 },
  { "sc.d",       0x1800302f, 0xf800707f, OP_STD_EXT,    0 },
  { "amoswap.d",  0x0800302f, 0xf800707f, OP_STD_EXT,    0 },
  { "amoadd.d",   0x0000302f, 0xf800707f, OP_STD_EXT,    0 },
  { "amoxor.d",   0x2000302f, 0xf800707f, OP_STD_EXT,    0 },
  { "amoand.d",   0x6000302f, 0xf800707f, OP_STD_EXT,    0 },
  { "amoor.d",    0x4000302f, 0xf800707f, OP_STD_EXT,    0 },
  { "amomin.d",   0x8000302f, 0xf800707f, OP_STD_EXT,    0 },
  { "amomax.d",   0xa000302f, 0xf800707f, OP_STD_EXT,    0 },
  { "amominu.d",  0xc000302f, 0xf800707f, OP_STD_EXT,    0 },
  { "amomaxu.d",  0xe000302f, 0xf800707f, OP_STD_EXT,    0 },
  { "flw",        0x00002007, 0x0000707f, OP_FD_INDEX_R, 0 },
  { "fsw",        0x00002027, 0x0000707f, OP_FS_INDEX_R, 0 },
  { "fmadd.s",    0x00000043, 0x0600007f, OP_FP_FP_FP_FP_RM, 0 },
  { "fmsub.s",    0x00000047, 0x0600007f, OP_FP_FP_FP_FP_RM, 0 },
  { "fnmsub.s",   0x0000004b, 0x0600007f, OP_FP_FP_FP_FP_RM, 0 },
  { "fnmadd.s",   0x0000004f, 0x0600007f, OP_FP_FP_FP_FP_RM, 0 },
  { "fadd.s",     0x00000053, 0xfe00007f, OP_FP_FP_FP_RM, 0 },
  { "fsub.s",     0x08000053, 0xfe00007f, OP_FP_FP_FP_RM, 0 },
  { "fmul.s",     0x10000053, 0xfe00007f, OP_FP_FP_FP_RM, 0 },
  { "fdiv.s",     0x18000053, 0xfe00007f, OP_FP_FP_FP_RM, 0 },
  { "fsqrt.s",    0x58000053, 0xfff0007f, OP_FP_FP_RM,    0 },
  { "fsgnj.s",    0x20000053, 0xfe00707f, OP_FP_FP_FP,    0 },
  { "fsgnjn.s",   0x20001053, 0xfe00707f, OP_FP_FP_FP,    0 },
  { "fsgnjx.s",   0x20002053, 0xfe00707f, OP_FP_FP_FP,    0 },
  { "fmin.s",     0x28000053, 0xfe00707f, OP_FP_FP_FP,    0 },
  { "fmax.s",     0x28001053, 0xfe00707f, OP_FP_FP_FP,    0 },
  { "fcvt.w.s",   0xc0000053, 0xfff0007f, OP_R_FP_RM,     0 },
  { "fcvt.wu.s",  0xc0100053, 0xfff0007f, OP_R_FP_RM,     0 },
  { "fmv.x.s",    0xe0000053, 0xfe00707f, OP_R_FP,        0 },
  { "feq.s",      0xa0002053, 0xfe00707f, OP_R_FP_FP,     0 },
  { "flt.s",      0xa0001053, 0xfe00707f, OP_R_FP_FP,     0 },
  { "fle.s",      0xa0000053, 0xfe00707f, OP_R_FP_FP,     0 },
  { "fclass.s",   0xe0001053, 0xfff0707f, OP_R_FP,        0 },
  { "fcvt.s.w",   0xd0000053, 0xfff0007f, OP_FP_R_RM,     0 },
  { "fcvt.s.wu",  0xd0100053, 0xfff0007f, OP_FP_R_RM,     0 },
  { "fmv.s.x",    0xf0000053, 0xfff0707f, OP_FP_R,        0 },
  { "frcsr",      0x00302073, 0xfffff07f, OP_READ,        0 },
  { "frrm",       0x00202073, 0xfffff07f, OP_READ,        0 },
  { "frflags",    0x00102073, 0xfffff07f, OP_READ,        0 },
  { "fscsr",      0x00301073, 0xfff0707f, OP_R_R,         0 },
  { "fsrm",       0x00201073, 0xfff0707f, OP_R_R,         0 },
  { "fsflags",    0x00101073, 0xfff0707f, OP_R_R,         0 },
  //{ "fsrmi",     0x00102073, 0xfffff07f, OP_FP,           0 },
  //{ "fsflagsi",  0x00302073, 0xfffff07f, OP_FP,           0 },
  { "fcvt.l.s",   0xc0200053, 0xfff0007f, OP_R_FP_RM,     0 },
  { "fcvt.lu.s",  0xc0300053, 0xfff0007f, OP_R_FP_RM,     0 },
  { "fcvt.s.l",   0xd0200053, 0xfff0007f, OP_FP_R_RM,     0 },
  { "fcvt.s.lu",  0xd0300053, 0xfff0007f, OP_FP_R_RM,     0 },
  { "fld",        0x00003007, 0x0000707f, OP_FD_INDEX_R,  0 },
  { "fsd",        0x00003027, 0x0000707f, OP_FS_INDEX_R,  0 },
  { "fmadd.d",    0x02000043, 0x0600007f, OP_FP_FP_FP_FP_RM, 0 },
  { "fmsub.d",    0x02000047, 0x0600007f, OP_FP_FP_FP_FP_RM, 0 },
  { "fnmsub.d",   0x0200004b, 0x0600007f, OP_FP_FP_FP_FP_RM, 0 },
  { "fnmadd.d",   0x0200004f, 0x0600007f, OP_FP_FP_FP_FP_RM, 0 },
  { "fadd.d",     0x02000053, 0xfe00007f, OP_FP_FP_FP_RM, 0 },
  { "fsub.d",     0x0a000053, 0xfe00007f, OP_FP_FP_FP_RM, 0 },
  { "fmul.d",     0x12000053, 0xfe00007f, OP_FP_FP_FP_RM, 0 },
  { "fdiv.d",     0x1a000053, 0xfe00007f, OP_FP_FP_FP_RM, 0 },
  { "fsqrt.d",    0x5a000053, 0xfff0007f, OP_FP_FP_RM,    0 },
  { "fsgnj.d",    0x22000053, 0xfe00707f, OP_FP_FP_FP,    0 },
  { "fsgnjn.d",   0x22001053, 0xfe00707f, OP_FP_FP_FP,    0 },
  { "fsgnjx.d",   0x22002053, 0xfe00707f, OP_FP_FP_FP,    0 },
  { "fmin.d",     0x2a000053, 0xfe00707f, OP_FP_FP_FP,    0 },
  { "fmax.d",     0x2a001053, 0xfe00707f, OP_FP_FP_FP,    0 },
  { "fcvt.s.d",   0x40100053, 0xfff0007f, OP_FP_FP_RM,    0 },
  // FIXME - Documentation says this can take an RM, gnu-as says otherwise
  { "fcvt.d.s",   0x42000053, 0xfff0007f, OP_FP_FP,       0 },
  { "feq.d",      0xa2002053, 0xfe00707f, OP_R_FP_FP,     0 },
  { "flt.d",      0xa2001053, 0xfe00707f, OP_R_FP_FP,     0 },
  { "fle.d",      0xa2000053, 0xfe00707f, OP_R_FP_FP,     0 },
  { "fclass.d",   0xe2001053, 0xfff0707f, OP_R_FP,        0 },
  { "fcvt.w.d",   0xc2000053, 0xfff0007f, OP_R_FP_RM,     0 },
  { "fcvt.wu.d",  0xc2100053, 0xfff0007f, OP_R_FP_RM,     0 },
  // FIXME - Documentation says this can take an RM, gnu-as says otherwise
  { "fcvt.d.w",   0xd2000053, 0xfff0007f, OP_FP_R,        0 },
  // FIXME - Documentation says this can take an RM, gnu-as says otherwise
  { "fcvt.d.wu",  0xd2100053, 0xfff0007f, OP_FP_R,        0 },
  { "fcvt.l.d",   0xc2200053, 0xfff0007f, OP_R_FP_RM,     0 },
  { "fcvt.lu.d",  0xc2300053, 0xfff0007f, OP_R_FP_RM,     0 },
  { "fmv.x.d",    0xe2000053, 0xfff0707f, OP_R_FP,        0 },
  { "fcvt.d.l",   0xd2200053, 0xfff0007f, OP_FP_R_RM,     0 },
  { "fcvt.d.lu",  0xd2300053, 0xfff0007f, OP_FP_R_RM,     0 },
  { "fmv.d.x",    0xf2000053, 0xfff0707f, OP_FP_R,        0 },
  { NULL,                  0,          0,                  0  }
};

