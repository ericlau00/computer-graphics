#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;

  c.red = 255;
  c.blue = 0;
  c.green = 0;

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

  clear_screen(s);
  draw_lines(m2, s, c);
  // display(s);
  // save_extension(s, "lines.png");
  // save_ppm(s, "binary.ppm");
  // save_ppm_ascii(s, "ascii.ppm");

  free_matrix(m1);
  free_matrix(m2);
}
