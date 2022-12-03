# Room #

## Written in C++ ##

This program uses three measurement values for a room to tell the user:
*Area of the Room floor
*Volume of the Room
*Amount of paint required to paint the wall

The last requirement accounts for the possibility of windows and therefore asks further uestions to the user about the size
of those windows.

All values are placed in metres but are float values to allow for decimel values.

All code followed the Interceptor Project C++ Coding standards, this c++ file has not been peer reviewed nor
has it been unit tested. Thats a future aim to create a suitable test harness that will individually test each 
function in the program.

Splitting the class out into a separate package would be a future aim as well.

If you are looking at the code and wondering how to follow it through linearly here is a representation by function name to help
gauge what is each stage of the simple program.

## Compile ##

g++ -o room Room.cpp

## Map ##

main

Object_Instance

Create instance of the class Generic_Room called Room

Room.Initialise

Room.setDimensions

Room.calculateArea

Room.calculateVolume

Room.setWindows

Room.calculateWindowAreas

Room.calculateTotalWindowArea

Room.getPaintRequired
