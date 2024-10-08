#include <stdio.h>
#include "draw.h" // project-related declarations

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Triangle = t, Square = s, Arrow = a, Chars = c) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;

    //What is the point of this while?? --------------------
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call

    //The instructions say that we are to add a "t" commnad
    // but there is already a t command. 
    // Asumpution: add a command, no matter the letter. 
    switch (c) {
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;

    case 'a':
      puts("You selected arrow");
      print_arrow(9);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      puts("You selected chars:");
      const char *message = "Hello!";
      print_string_11x16(message);
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
