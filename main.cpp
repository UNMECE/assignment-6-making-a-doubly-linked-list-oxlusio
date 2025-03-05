#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "coordinate.h"

void add_coordinate(Coordinate *list_end, float x; float y); //adds a coordinate to the end of a linked list
void forward_display(Coordinate *list_beginning); // displays all coordinates from beginning to end
void backward_display(Coordinate *list_end); // displays all coodinates from end to beginning
void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete); // removes a coordinate from the linked list (free memory)
int list_length(Coordinate *list_beginning); // returns the length of the list
void closest_to(Coordinate *list_beginning, float x, float y); // finds the coordinate that is closests to the given x,y and the output the distance between the 2


