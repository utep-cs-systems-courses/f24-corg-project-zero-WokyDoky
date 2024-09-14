#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */   //Why not use <stdio.h> ?? ------------------

void print_char_5x7(char c)
{
  c -= 0x20; 
  for (char col = 0; col < 5; col++) {
    for (char row = 0; row < 7; row++) {
      unsigned short rowBits = font_5x7[c][col];
      unsigned short colMask = 1 << (6-row); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
  putchar('\n');
}

void print_char_11x16(char c)
{
  c -= 0x20;
  printf("font\n");
  for (char row = 0; row < 11; row++) {
    unsigned short rowBits = font_11x16[c][row];
    for (char col = 0; col < 16; col++) {
      unsigned short colMask = 1 << (15 - col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? 'X' : 'O');
    }
    putchar('\n');
  }
  putchar('\n');
}

//Hola hola hola hola
