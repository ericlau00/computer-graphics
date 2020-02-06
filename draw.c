#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    int x = x0;
    int y = y0;
    int a = y1 - y0;
    int b = -1 * (x1 - x0);
    int d;
    if (b == 0) {
        // vertical line
    }
    else {
        double m = a / (-1.0 * b);
        d = 2 * a + b;
        if(0 <= m && m <= 1) {
            // octant I
            d = 2 * a + b;
            while(x <= x1) {
                plot(s, c, x, y);
                if (d > 0) {
                    y++;
                    d += 2 * b;
                }
                x++;
                d += 2 * a;
            }
        } else if(m > 1) {
            // octant II
            d = a + 2 * b;
            while(y <= y1) {
                plot(s, c, x, y);
                if (d < 0) {
                    x++;
                    d += 2 * a;
                }
                y++;
                d += 2 * b;
            }
        } else if (m < -1) {
            // octant III
            d = -1 * a + 2 * b;
            while(y <= y1) {
                plot(s, c, x, y);
                if (d > 0) {
                    x--;
                    d -= 2 * a;
                }
                y++;
                d += 2 * b;
            }
        } else if (m > -1) {
            // octant IV
            d = -2 * a + b;
            while(x >= x1) {
                plot(s, c, x, y);
                if (d < 0) {
                    y++;
                    d += 2 * b;
                }
                x--;
                d -= 2 * a;
            }
        }
    }
}
