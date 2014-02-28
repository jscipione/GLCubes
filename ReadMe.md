# GLCubes+ v0.9g
## by Brad Leffler

Screen Saver that displays bouncing OpenGL® cubes on the screen.

![GLCubes screenshot](https://raw.github.com/jscipione/GlCubes/master/GLCubes.png)

![GLCubes movie](https://raw.github.com/jscipione/GlCubes/master/GLCubes.gif)

### Disclaimer

This screen saver module is still being tested and your mileage may vary. Basically it means that I'm not responsible if it breaks your computer, makes your woman leave you, kills your hamster or anything else bad that it's usage might cause.

### HISTORY

8/16/2000 - v0.9g
 This version introduces new shape selections, hence the name 'upgrade' to GL Cubes+. The shape choices now include Pyramid, Gem and Diamond. And at long last, I have finally implemented a basic Collision option. It's a bit buggy at the moment, and while some collisions are perfect, other times the shapes  get tangled up in each other. 

8/6/2000 - v0.9f
 It's been a long time! I've been holding out for the new OpenGL kit, but I couldn't wait any longer to work on GLCubes again. A nasty break in the code popped up between R4.5 and R5 with the addition of the libscreensaver.so, so the code has all been merged into one .cpp file and one header file. I've added an extra function called 'Pulsate' which gives the cubes, ummm, a pulsating change in shape. I'm adding another option soon to be able to select solid colors for all the cubes as well. This version is compiled under 5.0.2, so I don't know if there are any compatibility issues with previous releases of the OS. 

2/12/2000 - v0.9e
 Added Transparent cubes. This and other visual features combined are slowing the frame rate down considerably in software mode. Still looks great when using the experimental Glide support. I certainly hope we get some complete OpenGL acceleration with the impending R5!!!

2/7/2000 - v0.9d
 With a little inspiration from Kevin Pulley I've added basic lighting. Not quite what Kevin had tried with the source, but ultimately the effect is there. A few small refinements, and the source is a bit cleaner.

1/23/2000 - v0.9c
 Complete rewrite of code for source release. Source is included with archive. Added 'Fountain' mode - cubes spawn continuously from screen center. Removed 'Cube Size' slider as it really didn't add much effect. Tweaked other modes to remove cube popping at screen edges. NOTE: The name of the saver module has been changed, (Yes, by one letter. Call me a dork for a lack of consistency!) so you may want to remove the old module - GLCube.

1/19/2000 - v0.9b
Fixed checkboxes - No Bounds and Wireframe are functional now. Removed Collision checkbox until code is implemented properly.

1/18/2000 - v0.9a
Initial release. Tested on a few systems. So far it works fine with or without Be's experimental 3dfx hardware acceleration support.


### INSTALLATION

Drag the module into folder labeled 'Drop Saver Here'
Enjoy.

If you can't do that then quit using a computer and go buy a Nintendo… the old one.


### FUTURE

Finish up collision option, possibly texture mapping, and whatever else I can think of.

### FEEDBACK

Please report any bugs that you might find, and tell me what you think.  If for whatever reason, you did not receive the source please contact me.

Brad Leffler
brad@sitebe.com
ICQ# - 3496032
IRC - Schmedly (EFNET - #beos and or #bedev)