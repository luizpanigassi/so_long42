Alright, now things are getting interesting. We are supposed to create a mini 2D game using MiniLibX,
a proprietary library of 42 to generate windows, capture keystrokes and manage everything. I am still
Developing everything, it's been a bit challenging.

First things first, the game needs to load map assets from .ber files, which will contain indicators of
open spaces (0s), walls (1s), the character (P), the exit (E) and collectibles (C). The map must be
rectangular, surrounded by walls, the character must not go through the walls, and can only take the exit
after collecting all of the collectibles. The map must be validated before anything happens, to check if
all the conditions are valid.

After validating, we must check all the map so we can place the respective sprites where they should be,
render everything, then add keyhooks so we can move the character using WASD or the arrow keys. Esc must
close the window, as well as pressing the X button on the window, and the terminal must register how many
steps were taken.

Be patient, guys. It's ugly as hell, but I'm getting there. This version loads the map, renders everything,
and the logic of the collectibles and exit are working fine. But it needs to be refined. Stay tuned.
