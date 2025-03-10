#include "coordinate.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cer << "Usage: " << argv[0] << " <number_of_coordinates>\n";
		return 1;
	}

	int num_coordinates = std::atoi(argv[1]);
	if (num_coordinates <= 0) {
		std::cer << "Please eneter a positive number of coordinates.\n";
		return 1;
	}

	std::srand(std::time(0));
	Coordinate *list_beginning = nullptr;
	Coordinate *list_end = nullptr;

	int i;
	for ( i = 0; i < num_coordinate; ++i) {
		float x = static_cast<float>(std::rand()) / RAND_MAX * 100;
		float y = static_cast<float>(std::rand()) / RAND_MAX * 100;

		if (list_beginning == nullptr) {
			list_beginning = new Coordinate{x, y, current_id++, nullptr, nullptr};
			list_end = list_beginning;
			} else {
				add_coordinates(list_end, x, y);
				list_end = list_end->next;
			}
		}

	std::cout << "Forward display:\n";
	forward_display(list_beginning);

	std::cout << "\nBackward display:\n";
	backward_display(list_end);

	int coord_id_to_delete;
	std::cout << "\n"Enter the ID of the coordinate to delete: ";
	std::cin >> coord_id_to_delete;
	delete_coordinate(list_beginning, coord_id_to_delete);

	std::cout << "\nList after deletion:\n";
	forward_display(list_beginning);

	float x, y;
	std::cout << "\nEnter an x and y coordinate to find the closest point: ";
	std::cin >> x >> y;
	closet_to(list_beginning, x, y);

	return 0;
}
