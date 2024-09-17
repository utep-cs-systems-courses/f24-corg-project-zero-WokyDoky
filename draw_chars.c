#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */   //Why not use <stdio.h> ?? ------------------

void print_char_5x7(char c)
{
c -= 0x20; 
  for (int col = 0; col < 5; col++) {
    for (int row = 0; row < 7; row++) {
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
  putchar('\n');
  for (int col = 0; col < 11; col++) {
    for (int row = 0; row < 16; row++) {
      unsigned short rowBits = font_11x16[c][col];
      unsigned short colMask = 1 << (15 - row); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
  putchar('\n');
}

void print_string_11x16(const char *str) {
    while (*str) { // Loop through each character in the string until null terminator
        print_char_11x16(*str);
        str++; // Move to the next character
    }
}
