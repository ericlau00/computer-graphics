#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gmath.h"
#include "matrix.h"
#include "ml6.h"


//vector functions
//normalize vector, should modify the parameter
void normalize( double *vector ) {
}

//Return the dot porduct of a . b
double dot_product( double *a, double *b ) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}


//Calculate the surface normal for the triangle whose first
//point is located at index i in polygons
double *calculate_normal(struct matrix *polygons, int i) {
  double x0, y0, z0, x1, y1, z1, x2, y2, z2;

  x0 = polygons->m[0][i];
  y0 = polygons->m[1][i];
  z0 = polygons->m[2][i];

  x1 = polygons->m[0][i+1];
  y1 = polygons->m[1][i+1];
  z1 = polygons->m[2][i+1];

  x2 = polygons->m[0][i+2];
  y2 = polygons->m[1][i+2];
  z2 = polygons->m[2][i+2];

  double a[3] = {x1 - x0, y1 - y0, z1 - z0};
  double b[3] = {x2 - x0, y2 - y0, z2 - z0};

  double * n = malloc(sizeof(double *));
  n[0] = a[1] * b[2] - a[2] * b[1];
  n[1] = a[2] * b[0] - a[0] * b[2];
  n[2] = a[0] * b[1] - a[1] * b[0];

  return n;
}
