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

int read_line(char str[], int n)
{
  int ch, i = 0;

  for(;;) {
    ch = getchar();
    if (ch != '\n' && i < n) {
      if (isspace(ch)) 
        continue;
      if (ch == EOF) 
        break;
      
      str[i++] = ch;
    } else {
      break;
    }
  }
  str[i] = '\0';
  return i;
}
