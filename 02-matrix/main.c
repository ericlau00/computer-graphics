#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int  draw_rainbow(struct matrix * rainbow, int x, int y, int minx, int xoff, screen s, color c) {
  for(; x > minx; y++) {
    if(y % 2 == 0) {
      x--;
    }
    add_edge(rainbow, x - xoff, y, 0, 499, y - 48, 0);
  }

  draw_lines(rainbow, s, c);

  rainbow->lastcol = 0;
  return y;
}

int main() {

  struct matrix *m2;
  struct matrix *m1;

  m1 = new_matrix(4, 4);
  m2 = new_matrix(4, 4);

  printf("Testing add_edge. Adding (1, 2, 3), (4, 5, 6) m2 =\n");

  add_edge(m2, 1, 2, 3, 4, 5, 6);
  print_matrix(m2);

  printf("\nTesting ident. m1 =\n");

  ident(m1);
  print_matrix(m1);

  printf("\nTesting Matrix mult. m1 * m2 =\n");

  matrix_mult(m1, m2);
  print_matrix(m2);

  printf("\nTesting Matrix mult. m1=\n");

  copy_matrix(m2, m1);
  m1->lastcol = 2;
  add_edge(m1, 7, 8, 9, 10, 11, 12);
  print_matrix(m1);

  printf("\nTesting Matrix mult. m1 * m2 = \n");

  matrix_mult(m1, m2);
  print_matrix(m2);

  free_matrix(m1);
  free_matrix(m2);

  screen s;

  color white;
  white.red = 255;
  white.green = 255;
  white.blue = 255;

  clear_screen(s);

  struct matrix * streak;
  struct matrix * refraction;
  struct matrix * prism;
  struct matrix * rainbow;

  streak = new_matrix(4, 8);
  refraction = new_matrix(4, 4);
  prism = new_matrix(4, 6);
  rainbow = new_matrix(4, 48);

  int x = 227;
  for(; x < 231; x++) {
    add_edge(streak, 0, x, 0, x - 29, x + 52, 0);
  }

  add_edge(prism, 141, 180, 0, 250, 369, 0);
  add_edge(prism, 250, 369, 0, 358, 180, 0);
  add_edge(prism, 358, 180, 0, 141, 180, 0);

  add_edge(refraction, 198, 279, 0, 312, 259, 0);
  add_edge(refraction, 201, 284, 0, 289, 301, 0);

  draw_lines(streak, s, white);
  draw_lines(prism, s, white);
  draw_lines(refraction, s, white);

  color c;
  c.red = 131;
  c.green = 75;
  c.blue = 146;

  int y = draw_rainbow(rainbow, 314, 259, 311, 0, s, c);

  c.red = 7;
  c.green = 182;
  c.blue = 225;

  y = draw_rainbow(rainbow, 311, y, 307, 1, s, c);

  c.red = 108;
  c.green = 190;
  c.blue = 82;

  y = draw_rainbow(rainbow, 307, y, 303, 1, s, c);

  c.red = 249;
  c.green = 243;
  c.blue = 45;

  y = draw_rainbow(rainbow, 303, y, 299, 2, s, c);

  c.red = 245;
  c.green = 145;
  c.blue = 49;

  y = draw_rainbow(rainbow, 299, y, 295, 3, s, c);

  c.red = 243;
  c.green = 46;
  c.blue = 66;

  y = draw_rainbow(rainbow, 295, y, 293, 3, s, c);

  free_matrix(streak);
  free_matrix(prism);
  free_matrix(refraction);
  free_matrix(rainbow);

  // display(s);
  save_extension(s, "lines.png");
  save_ppm(s, "binary.ppm");
  save_ppm_ascii(s, "ascii.ppm");
}
