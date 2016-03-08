/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* xor.c (Chapter 20, page 515) */
/* Performs XOR encryption */

#include <ctype.h>
#include <stdio.h>

#define KEY '&'

int main(void)
{
  int orig_char, new_char;

  while ((fread(&orig_char, sizeof(char), 1, stdin)) != 0) {
    new_char = orig_char ^ KEY;
    fwrite(&new_char, sizeof(char), 1, stdout);
  }

  return 0;
}