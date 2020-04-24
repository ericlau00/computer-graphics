
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gmath.h"
#include "matrix.h"
#include "ml6.h"


/*============================================
  IMPORANT NOTE

  Ambient light is represeneted by a color value

  Point light sources are 2D arrays of doubles.
       - The fist index (LOCATION) represents the vector to the light.
       - The second index (COLOR) represents the color.

  Reflection constants (ka, kd, ks) are represened as arrays of
  doubles (red, green, blue)
  ============================================*/


//lighting functions
color get_lighting( double *normal, double *view, color alight, double light[2][3], double *areflect, double *dreflect, double *sreflect) {
  color i;
  color i_a = calculate_ambient(alight, areflect);
  color i_d = calculate_diffuse(light, dreflect, normal);
  color i_s = calculate_specular(light, sreflect, view, normal);
  i.blue = i_a.blue + i_d.blue + i_s.blue;
  i.green = i_a.green + i_d.green + i_s.green;
  i.red = i_a.red + i_d.red + i_s.red;
  limit_color(&i);
  return i;
}

color calculate_ambient(color alight, double *areflect ) {
  color a;
  a.blue = alight.blue * *areflect;
  a.green = alight.green * *areflect;
  a.red = alight.red * *areflect;
  return a;
}

color calculate_diffuse(double light[2][3], double *dreflect, double *normal ) {
  color d;
  normalize(normal);
  normalize(light[0]);
  double cos_theta = dot_product(normal, light[0]);
  if(cos_theta < 0) cos_theta = 0;
  double x = *dreflect * cos_theta;
  d.red = light[1][0] * x;
  d.green = light[1][1] * x;
  d.blue = light[1][2] * x;
  return d;
}

color calculate_specular(double light[2][3], double *sreflect, double *view, double *normal ) {
  color s;
  normalize(normal);
  normalize(light[0]);
  double product = dot_product(normal, light[0]);
  if (product < 0) product = 0;
  double * reflection = (double *)malloc(3 * sizeof(double));
  reflection[0] = 2 * normal[0] * (product) - light[0][0];
  reflection[1] = 2 * normal[1] * (product) - light[0][1];
  reflection[2] = 2 * normal[2] * (product) - light[0][2];
  normalize(reflection);
  normalize(view);
  double cos_alpha = dot_product(reflection, view);
  double x = *sreflect * pow(cos_alpha, 8);
  s.red = light[1][0] * x;
  s.green = light[1][1] * x;
  s.blue = light[1][2] * x;
  return s;
}

//limit each component of c to a max of 255
void limit_color( color * c ) {
  if(c->blue > 255) {
    c->blue = 255;
  }
  if(c->green > 255) {
    c->green = 255;
  }
  if(c->red > 255) {
    c->red = 255;
  }
}

//vector functions
//normalize vetor, should modify the parameter
void normalize( double *vector ) {
  double magnitude;
  magnitude = sqrt( vector[0] * vector[0] +
                    vector[1] * vector[1] +
                    vector[2] * vector[2] );
  int i;
  for (i=0; i<3; i++) {
    vector[i] = vector[i] / magnitude;
  }
}

//Return the dot porduct of a . b
double dot_product( double *a, double *b ) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}


//Calculate the surface normal for the triangle whose first
//point is located at index i in polygons
double *calculate_normal(struct matrix *polygons, int i) {

  double A[3];
  double B[3];
  double *N = (double *)malloc(3 * sizeof(double));

  A[0] = polygons->m[0][i+1] - polygons->m[0][i];
  A[1] = polygons->m[1][i+1] - polygons->m[1][i];
  A[2] = polygons->m[2][i+1] - polygons->m[2][i];

  B[0] = polygons->m[0][i+2] - polygons->m[0][i];
  B[1] = polygons->m[1][i+2] - polygons->m[1][i];
  B[2] = polygons->m[2][i+2] - polygons->m[2][i];

  N[0] = A[1] * B[2] - A[2] * B[1];
  N[1] = A[2] * B[0] - A[0] * B[2];
  N[2] = A[0] * B[1] - A[1] * B[0];

  return N;
}
