# computer-graphics

Computer Graphics w/ JonAlf Dyrland-Weaver at Stuyvesant 2019-2020

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
