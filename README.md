# PS2: Pythagorean Tree

## Contact
Name: Vy Tran
Section: 201
Time to Complete: 5 hours

## Description
The code generates Pythagorean Tree in gradient color. It makes sure the window size is big enough to fit given the input of number of leaves. Tree is generated recursively. SFML library is used for rendering and transformation of the shape.

### Features
Run generation recursively, every parent square generates 2 children squares rotated by 45 degrees until recursion runs out. sf::Transform::transformPoint is used to do the math of figuring out where the next square should be.

### Issues
Tried to do the math by hand first but it was too complex for right side square. Found that existing SFML library can do translation. Also color goes from red to blue, doesn't go through entire rainbow to avoid unnecessary complexity.

### Extra Credit
Tree is rendered in multiple colors as a gradient.

## Acknowledgements
Class notes, SFML and C++ documentaiton, search engine.
