/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* readline.c (Chapter 16, page 395) */

#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int fread_line(char str[], int n, FILE *fp)
{
  int ch, i = 0;

  while (isspace(ch = getc(fp)))
    ;
  while (ch != '\n' && ch != EOF) {
    if (i < n)
      str[i++] = ch;
    ch = getc(fp);
  }
  str[i] = '\0';
  return i;
}

int read_line(char str[], int n) {
  return fread_line(str, n, stdin);
}
