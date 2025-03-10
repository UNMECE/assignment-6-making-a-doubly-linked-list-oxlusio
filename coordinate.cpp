#include "coordinate.h"
#include <iostream>
#include <cmath>

static int current_id = 0;

void add_coordinate(Coordinate *list_end, float x, float y) {
	Coordinate *new_coord = new Coordinate;
	new_coord->x = x;
	new_coord->y = y;
	new_coord->coord_id = current_id++;
	new_coord->next = nullptr;
	new_coord->previous = list_end;
	if (list_end != nullptr) {
		list_end->next = new_coord;
	}
}

void forward_display(Coordinate *list_beginning) {
	Coordinate *current = list_beginning;
	while (current != nullptr) {
		std::cout << "ID: " << current ->coord_id << " (x: " << current->x << ", y: " <<current->y << ")\n";
		current = current->next;
	}
}

void backward_display(Coordinate *list_end) {
	Coordinate *current = list_end;
	while (current != nullptr) {
		std::cout << "ID: " << current->coord_id << " (x: " << current->x << ", y: " << current->y << ")\n";
		current = current->previous;
	}	
}

void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete) {
	Coordinate *current = list_beginning;
	while (current != nullpty) {
		if (current->coord_id == coord_id_to_delete) {
			if (current->previous != nullptr) {
				current->previous->next = current->next;
			}
			if (current->next != nullptr) {
				current->next->previous = current->previous;
			}
			delete current;
			return;
		}
		current = current->next;
		}
	}

int list_length(Coordinate *list_beginning) {
	int length = 0;
	Coordinate *current = list_beginning;
	while (current != nullptr) {
		length++;
		current = current->next;
		}
		return length;
}

void closest_to(Coordinate *list_beginning, float x, float y) {
	Coordinate *current = list_beginning;
	Coordinate *closest = nullptr;
	float min_distance = std::numeric_limits<float>::max();

	while (current != nullptr) {
		float distance = std::sqrt(std::pow(current->x - x, 2) + std::pow(current-> y - y, 2));
		if (distance < min_distance) {
			min_distance = distance:
			closest = current;
		}
		current = current->next;
	}

	if (closest != nullptr) {
		std::cout << "Closest coordinate to {" << x << ", " <<  y << ") is ID: " << closest->coord_id << " (x " << closest->x << ", y: " << closest->y << ") with distance: " <<min_distance << "\n";
		} else { 
			std::cout << "No coodinates found.\n";
		}
}

