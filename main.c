#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;

  struct matrix *m2;
  struct matrix *m1;

  m1 = new_matrix(4, 4);
  m2 = new_matrix(4, 4);

  printf("Testing add_edge. Adding (1, 2, 3), (4, 5, 6) m2 =\n");

  add_edge(m2, 1, 2, 3, 4, 5, 6);
  print_matrix(m2);

  printf("Testing ident. m1 =\n");

  ident(m1);
  print_matrix(m1);

  printf("Testing Matrix mult. m1 * m2 =\n");

  printf("Testing Matrix mult. m1=\n");

  printf("Testing Matrix mult. m1 * m2 = \n");

  free_matrix(m2);
}
