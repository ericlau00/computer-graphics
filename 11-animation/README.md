# Work 11: Gettin' Giffy With It

## Due: Monday 05/11 10:00am

GitHub link: <https://github.com/mks66/animation.git>

Animation! Woohoo!
**New MDL commands to implement:**

- `frames`
  - set the number of frames
- `basename`
  - sets the basename for animation file saving
- `vary`
  - vary the values for a knob between 2 values in a set range of frames
- Animation Features:
  - The key animation commands are frames, basename and vary. You should proceed with animation code in 3 steps:
  1. Go through the operations list and look for any of the three animation commands
     - Set frames and basename
     - Handle erros as needed
  2. Go through the operations list a second time and look for the vary command
     - Populate a table that has an entry for each frame, and in each frame it has a value for each knob
     - When completed, the table should contain the correctly set values for each knob (perform the varying calculation)
     - In c, there is a `struct vary_node` defined in parser.h
     - In python, you could use a dictionary/list combination
     - Handle errors as needed (i.e. if the frame order for vary is bad)
  3. Perform the normal interpreting/drawing steps that are currently working, with the following additions if animation code is present.
     - First, look at the table of knob values (set in the second step) and set each knob in the symbol table to the appropriate value.
     - Run the normal commands
     - At the end of the loop, save the current screen to a file, the file should have the basename followed by a number, so that animate will work correctly.
     - I suggest you put all the animation frames in a subdirectory, so just append a directory name to the basename when saving files
     - Github does not track empty directories, so much sure there’s a placeholder file in your when you submit your work. * in c, you can pad the beginning of a string with 0’s using the following syntax (if x = 12):
     - `sprintf (s, "%03d", x )` will set `s` to the string `"012"`
     - The 0 indicates that you are padding with 0, and the 3 indicates that if x is less that 3 digits in length the number will be padded with 0 * python has similar functionality using python formatted strings
     - `"%03d"%12` will give you `"012" *` When you are done with each frame loop, don’t forget to reset the screen, origin stack and any other pieces of data that are specific to a given frame * Once you have all the files created, you can generate the animation using imagemagick’s animate and convert commands: `* animate`
     - Will display multiple single image files in succession as a single animation, with a default frame rate of 100 frames per second, by using the -delay option, you can change the fps ( -delay x will set the frame rate to 100/x fps )
     - `$ animate -delay 1.7 animations/orb* * convert` can, like animate, take a number of frames and animate them, but instead of displaying the animation, it will combine them into a single animated gif file. Note that the only image format that can use animation is gif.
     - `$ convert -delay 10 animations/orb* orb.gif` will create a single animated gif called orb.gif * In python and c, I’ve included a `make_animation` function in `display.c/py` that will generate the animation for you.
