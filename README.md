# Turtle for LaFortuna

This project seeks to bring the simplicity of Turtle graphics to the LaFortuna!
By using the graphics library from Steve Gunn in combination with a modified version of the AdaFruit main GFX library, the core functionality of Turtle graphics have been implemented, making drawing to the screen far more convenient.
The method signatures are for the most part the same as the Turtle implementation for Python, so programs look far more familiar.

To get started with the library simply clone this project and flash it to your LaFortuna using the included MakeFile. This includes a demo program to highlight some of the functionality of the library to give you ideas on what you could write, from simple polygons to fractal structures. The turtle.h header file and the demo.c file are great places to start.

Important Notes:
-The whole heading system is in DEGREES with 0 being up
-The coordinate system has the origin at the top left of the screen, but you can use the home() function to move to the centre of the screen.
