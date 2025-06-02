# LCDigits

## Problem Description

Your task is to create an LCD string representation of an integer value using a
3x3 grid of space, underscore, and pipe characters for each digit. Each digit 
is shown below (using a dot instead of a space).

._.   ...   ._.   ._.   ...   ._.   ._.   ._.   ._.   ._.
|.|   ..|   ._|   ._|   |_|   |_.   |_.   ..|   |_|   |_|
|_|   ..|   |_.   ._|   ..|   ._|   |_|   ..|   |_|   ..|


Example: 910

._. ... ._.
|_| ..| |.|
..| ..| |_|

Additional requirements: 

The use case I am designing for is a fixed-width display, where the intent is 
for it to display a single number (i.e. a digital clock). With that in mind, 
assume the display is of a fixed width. Numbers with fewer digits than the 
width of the display should be right-justified with no leading 0s.

(source: https://github.com/garora/TDD-Katas/blob/main/src/README.md)
