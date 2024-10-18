/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: https://www.mikekohn.net/
 * License: GPLv3
 *
 * Copyright 2010-2024 by Michael Kohn
 *
 */

#ifndef NAKEN_ASM_OPERATOR_H
#define NAKEN_ASM_OPERATOR_H

class Operator
{
public:
  Operator() :
    operation  (OPER_UNSET),
    precedence (PREC_UNSET)
  {
  }

  bool is_unset() { return operation == OPER_UNSET; }
  bool is_set()   { return operation != OPER_UNSET; }

  void reset()
  {
    operation  = OPER_UNSET;
    precedence = PREC_UNSET;
  }

  bool is_math_operator(const char *token);
  bool set_operator(const char *token);
  const char *to_string();

  enum
  {
    PREC_NOT,
    PREC_MUL,
    PREC_ADD,
    PREC_SHIFT,
    PREC_AND,
    PREC_XOR,
    PREC_OR,
    PREC_UNSET
  };

  enum
  {
    OPER_UNSET,
    OPER_NOT,
    OPER_MUL,
    OPER_DIV,
    OPER_MOD,
    OPER_PLUS,
    OPER_MINUS,
    OPER_LEFT_SHIFT,
    OPER_RIGHT_SHIFT,
    OPER_AND,
    OPER_XOR,
    OPER_OR
  };

  int operation;
  int precedence;
};

#endif

