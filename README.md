# computer-graphics

Computer Graphics w/ JonAlf Dyrland-Weaver at Stuyvesant 2019-2020

This repository contains notes and assignments from the course.

## Wednesday, Thursday 11, 12 March 2020

## 3D Shapes

### Box

- Given
  - vertex (front-top-left)
  - Length, height, depth (x, y, z)
- Defining points are 8 vertices

### Sphere

- Given
  - center
  - radius
- Defining points are points on surface

```plaintext
x rotation        circle        sphere
[ 1  0     0   ] [ rcosθ ]   [   rcosθ   ]
[ 0 cosΦ -sinΦ ] [ rsinθ ] = [ rsinθcosΦ ]
[ 0 sinΦ  cosΦ ] [   0   ]   [ rsinθsinΦ ]

θ: angle used to generate circle 0 - 2PI OR 0 - PI
Φ: rotation angle for sphere     0 - PI  OR 0 - 2PI

for Φ: 0 - 2PI
  for θ: 0 - PI
    x = rcosθ + cx
    y = rsinθcosΦ + cy
    z = rsinθsinΦ + cz

for rot: 0 - 1
  for circ: 0 - 1
    x = rcos(circ * PI) + cx
    y = rsin(circ * PI)cos(rot * 2PI) + cy
    z = rsin(circ * PI)sin(rot * 2PI) + cz
```

### Torus

- Givens
  - Center
  - Distance from center to center of a crosssection (R)
  - Radius of the cross section (r)
- Defining points
  - points on the surface
- Torus = Circle + Translation + Rotation

```plaintext
translation rotation
      x        y
      y        x

y rotation     circle + translations         torus x y z
cosΦ 0 sinΦ        rcosθ + R            cosΦ(rcosθ + R)   + cx
0 1 0              rsinθ + R            rsinθ             + cy
-sinΦ 0 cosΦ          0                -sinΦ(rcosθ + R )  + cz
```

## Tuesday, Thursday, Friday 03, 05, 06 March 2020

## Curves

### Splines

- Cubic curves that are designed so that they can be combined in a smooth and continuous way
- Bezier curves
  - Given
    - 2 endpoints
    - n influence points (degree - 1)
  - Line
    - `P_t = (1 - t)P_0 + tP_1`
    - `x_t = (1 - t)x_0 + tx_1`
    - `y_t = (1 - t)y_0 + ty_1`
  - Quadratic
    - `Q_t = (1 - t)Q_0 + tQ_1`
    - `Q_0t = (1 - t)P_0 + tP_1`
    - `Q_1t = (1 - t)P_1 + tP_2`
    - `Q_t = (1 - t)[(1 - t)P_0 + tP_1] + t[(1 - t)P_1 +tP_2]`
    - `Q-t = (1 - t)^2(P_0) + 2t(1 - t)P_1 + t^2(P_2)`
  - Cubic
    - `R_t = (1 - t)R_0 + tR_1`
    - `R_0 = (1 - t)^2(P_0) + 2t(1 - t)(P_1) + t^2(P_2)`
    - `R_1 = (1 - t)^2(P_1) + 2t(1 - t)(P_2) + t^2(P_3)`
    - `R_t = (1 - t)[(1 - t)^2(P_0) + 2t(1 - t)(P_1) + t^2(P_2)] + t[(1 - t)^2(P_1) + 2t(1 - t)(P_2) + t^2(P_3)]`
    - `R_t = (1 - t)^3(P_0) + 3t(1 - t)^2(P_1) + 3t^2(1 - t)P_2 + t^3(P_3)`
    - `R_t = (-P_0 + 3P_1 - 3P_2 + P_3)t^3 + (3P_0 - 6P_1 + 3P_2)t^2 + (-3P_0 + 3P_1)t + P_0`
  - `d + t(c + t(b + ta))` is computationally more efficient than `at^3 + bt^2 + ct + d`
- Hermite curves
  - Defined by:
    - 2 endpoints (P_0 and P_1)
    - rates of change at each endpoint (R_0 and R_1)
  - `f(t) = at^3 + bt^2 + ct + d` gives you points
  - `f'(t) = 3at^2 + 2bt + c` gives you rates of change
  - `f(0) = d` : P_0
  - `f'(0) = c`: R_0
  - `f(1) = a + b + c + d` : P_1
  - `f'(1) = 3a + 2b + c` : R_1

```plaintext
matrix H   * matrix C  ->      matrix G
[ 0 0 0 1 ]    [a]         [       d       ] (P_0)
[ 1 1 1 1 ]    [b]     ->  [ a + b + c + d ] (R_0)
[ 0 0 1 0 ]    [c]         [       c       ] (P_1)
[ 3 2 1 0 ]    [d]         [  3a + 2b + c  ] (R_1)

H * C = G
C = H^(-1) * G

     H^(-1)    *  G   =                 C
[  2 -2  1  1 ] [P_0]   [  2P_0 - 2P_1 +  R_0 + R_1 ] (a)
[ -3  3 -2 -1 ] [P_1]   [ -3P_0 + 3P_1 - 2R_0 - R_1 ] (b)
[  0  0  1  0 ] [R_0]   [             R_0           ] (c)
[  1  0  0  0 ] [R_1]   [             P_0           ] (d)
```

## Monday, 02 March 2020

### Parametric Equations

- Define curves as systems of equations in terms of a signel independent variable

- Non Parametric
  - y = f(x)
- Parametric
  - y = f(t)
  - x = g(t)

### Parametric Line

(x0, y0) -> (x1, y1)
x = x0 + (x1 - x0)t
y = y0 + (y1 - y0)t

### Circle

x = rcosθ + Cx => x = rcos(2πt) + Cx
y = rsinθ + Cy => y = rsin(2πt) + Cy

## Monday, Tuesday 24, 25 February 2020

### Master transformation

```plaintext
E0: EDGES T: TRANSLATE R: ROTATE S: SCALE

T * E0 = E1 : E0 -> TRANSLATED
R * E1 = E2 : E0 -> TRANSLATED -> ROTATED
S * E2 = E3 : E0 -> TRANSLATED -> ROTATED -> SCALED

E3 = S * E2
         E2 = R * E1
                  E1 = T * E0

E3 = (S * R * T) * E0

T is applied first
S is applied last
```

### Transformations

- scale, translate, rotate
- applied as matrix multiplication

#### Scale

```plaintext
(x, y, z) --- S_(a, b, c) -> (ax, by, cz)

[ a 0 0 0 ] [ x ]   [ ax ]
[ 0 b 0 0 ] [ y ]   [ by ]
[ 0 0 c 0 ] [ z ]   [ cz ]
[ 0 0 0 1 ] [ 1 ]   [ 1  ]
```

#### Translate

```plaintext
(x, y, z) --- T_(a, b, c) -> (x + a, y + b, z + c)

[ 1 0 0 a ] [ x ]   [ x + a ]
[ 0 1 0 b ] [ y ]   [ y + b ]
[ 0 0 1 c ] [ z ]   [ z + c ]
[ 0 0 0 1 ] [ 1 ]   [   1   ]
```

#### Rotate

```plaintext
x = rcosΦ
y = rsinΦ
x' = rcos(Φ + θ)
   = xcosθ - ysinθ
y' = rsin(Φ + θ)
y' = ycosθ + xsinθ

(x, y, z) --- R_(θ, z-axis) -> (xcosθ - ysinθ, ycosθ + xsinθ, z)

[ cosθ -sinθ 0 0 ] [ x ]   [ xcosθ - ysinθ ]
[ sinθ  cosθ 0 0 ] [ y ]   [ ycosθ + xsinθ ]
[  0     0   1 0 ] [ z ]   [       z       ]
[  0     0   0 1 ] [ 1 ]   [       1       ]

-----

y = rcosΦ
z = rsinΦ
y' = rcos(Φ + θ)
   = ycosθ - zsinθ
z' = rsin(Φ + θ)
   = zcosθ + ysinθ
(x, y, z) --- R_(θ, x-axis) -> (x, ycosθ - zsinθ, zcosθ + ysinθ)

[  1     0      0  0 ] [ x ]   [       x       ]
[  0    cosθ -sinθ 0 ] [ y ]   [ ycosθ - zsinθ ]
[  0    sinθ  cosθ 0 ] [ z ]   [ zcosθ + ysinθ ]
[  0     0     0   1 ] [ 1 ]   [       1       ]

-----

z = rcosΦ
x = rsinΦ
z' = rcos(Φ + θ)
   = xcosθ + zsinθ
x' = rsin(Φ + θ)
   = -xsinθ + zcosθ

(x, y, z) --- R_(θ, y-axis) -> (xcosθ + zsinθ, y, -xsinθ + zcosθ)

[ cosθ  0 sinθ  0 ] [ x ]   [ xcosθ + zsinθ ]
[  0    1  0    0 ] [ y ]   [       y       ]
[ -sinθ 0 cosθ  0 ] [ z ]   [-xsinθ + zcosθ ]
[  0    0  0    1 ] [ 1 ]   [       1       ]
```

## Tuesday, Wednesday 11-12 February 2020

### Matrices in Graphics

- We will maintain a list (matrix) of points that can represent an entire image.
- We will store points in an edge matrix such that each pair of points defines a seperate line.

```plaintext
p0 p1 p2 p3 pn-1 pn

p0 p1 defines a line
p2 p3 defines a line

a triangle would be defined by
p0 p1 p1 p2 p2 p0
```

- Each point is a set of (x, y) or (x, y, z) coordinates

```plaintext
x0 x1 ... xn-1 xn
y0 y1 ... yn-1 yn
z0 z1 ... zn-1 zn

columns make a point
rows are x to xn

(matrix / 2d array)
```

- Matrix Multiplication
  - M0 &#215; M1 != M1 &#215; M0
  - Number of columns of M0 must equal the number of rows in M1

```plaintext
            a
1  2  3  *  b = 1a + 2b + 3c
            c

(number of rows from M0, number of columns from M1)

          a d
1 2 3  *  b e = 1a + 2b + 3c  1d + 2e + 3f
          c f
```

```plaintext
x0     xn
y0 ... yn
z0     zn

3 by n matrix
```

3 by 3 matrix * 3 by n matrix = 3 by n matrix

```plaintext
1 0 0
0 1 0 is the identity matrix
0 0 1

2 0 0
0 2 0 is a scale by 2
0 0 2
```

```plaintext
TRANSFORMATION MATRIX     EDGE MATRIX
       1 0 0                x0 x1 xn
       0 1 0                y0 y1 yn
       0 0 1                z0 z1 zn

       3 x 3                3  by n
```

Matrix multiplication is always transformation matrix row multiplied by edge matrix column

## Monday, 3 February 2020

### Line Algorithm

## Wednesday, Thursday 29-30 January 2020

### Peering into the depths of color.

Color Space

- The possible colors for a pixel, and how the color is represented.

Color Depth

- The amount of data unsed to represent a single pixel

| depth | space |
|-|-|
| 1 bit | 1 color, on or off |
| 2 bit | 1 color with intensity |
| 3 bit | Red, Green, Blue, on or off |
| 4 bit | RGB with intensity |
| 6 bit | RGB, each color has its own intensity |
| 3 byte | RGB, each with 256 possible intensities |

4 bit depth gives 16 colors but they don't have to be RGB related. Can choose 16 random colors depending on bit mapping (color palettes).

#### Other Color Spaces

RGBA

- Red, Green, Blue + Alpha (transparency)
  - Alpha 0 = not transparent
  - Alpha 1 = fully transparent

HSB

- Hue, Saturation, Brightness
  - Hue is the base color
  - Saturation is the intensity of the color
  - Brightness
- Frequently used in computer vision

#### Image File Formats

Raster vs. Vector

- Vector image
  - Vector formats represent images as a series of drawing instructions
  - A triangle is comprised of three line commands
  - Infinitely scalable
  - Used for map applications
  - SVG (Scalable Vector Graphics) is a standard vector format
  - Not great for non-geometric instructions
- Raster image
  - Raster formats represent images as a grid of pixels.
  - Vector images on raster screens have to be converted into raster images.
  - Simpliest raster images are uncompressed (every pixel has a color value)
  - Uncompressed vs. Compressed (Raster)
    - Uncompressed formats contain data for each pixel
      - BMP (bit map format), TIFF, RAW
    - Compressed formats use a compression algorithm to minimize file fize.
    - Lossless vs. Lossy
      - Lossless compression algorithms contain enough information to exactly recreate the original image.
        - Run Length Encoding
        - PNG (Portable Network Graphics), GIF (Graphics Interchange Format)
      - Lossy compression algorithms do not retain all the details of the original image.
        - JPEG (Joint Photographic Experts Group)

```plaintext
RUN LENGTH ENCODING
BBBBBGGGRRR

B5G3R3
```

PPM (Portable PixMap)

- Uncompressed raster format
- Part of a family of formats called NETPBM
- Pixel data is represented by RGB triplets in either ASCII or binary.
- All whitespace is equivalent.

```PPM
P3
5 5
255
255 255 0 255 255 0 255 255 0 255 255 0 255 255 0
255 255 0 255 255 0 255 255 0 255 255 0 255 255 0
255 255 0 255 255 0 255 255 0 255 255 0 255 255 0
255 255 0 255 255 0 255 255 0 255 255 0 255 255 0
255 255 0 255 255 0 255 255 0 255 255 0 255 255 0
```
