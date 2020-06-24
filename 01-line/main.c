#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main(int argc, char * argv[]) {
  char choice[20];
  strcpy(choice, argv[1]);

  screen s;
  color c;

  c.red = 0;
  c.green = 255;
  c.blue = 0;

  clear_screen(s);

  if (strcmp(choice, "gallery") == 0) {
    int i = 0;

    c.red = 196;
    c.green = 183;
    c.blue = 155;

    for(; i < XRES - 1; i++) {
      draw_line(0, i, XRES - 1, i, s, c);
    }

    for(i = 0; i < 3000; i++) {
      c.red = i % 256;
      c.green = i % 256;
      c.blue = i % 256;
      draw_line(rand() % (XRES -1), rand() % (YRES -1), rand() % (XRES -1), rand() % (YRES -1), s, c);
    }
  } else if (strcmp(choice, "base") == 0 ) {
    // octants 1 and 5
    draw_line(0, 0, XRES-1, YRES-1, s, c); // 1
    draw_line(0, 0, XRES-1, YRES / 2, s, c); // 1
    draw_line(XRES-1, YRES-1, 0, YRES / 2, s, c); //5

    //octants 8 and 4
    c.blue = 255;
    draw_line(0, YRES-1, XRES-1, 0, s, c); //8
    draw_line(0, YRES-1, XRES-1, YRES/2, s, c); //8
    draw_line(XRES-1, 0, 0, YRES/2, s, c); //4

    //octants 2 and 6
    c.red = 255;
    c.green = 0;
    c.blue = 0;
    draw_line(0, 0, XRES/2, YRES-1, s, c); // 2
    draw_line(XRES-1, YRES-1, XRES/2, 0, s, c); //6

    //octants 7 and 3
    c.blue = 255;
    draw_line(0, YRES-1, XRES/2, 0, s, c); // 7
    draw_line(XRES-1, 0, XRES/2, YRES-1, s, c); // 3

    //horizontal and vertical
    c.blue = 0;
    c.green = 255;
    draw_line(0, YRES/2, XRES-1, YRES/2, s, c);
    draw_line(XRES/2, 0, XRES/2, YRES-1, s, c);
  }

  display(s);
  save_extension(s, "lines.png");
  save_ppm(s, "binary.ppm");
  save_ppm_ascii(s, "ascii.ppm");

  return 0;
}
