# computer-graphics

Computer Graphics w/ JonAlf Dyrland-Weaver at Stuyvesant 2019-2020

## Wednesday, 29 January 2020

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
