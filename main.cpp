#include <iostream>
#include <cstdlib>
#include <ctime>
#include "coordinate.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./main <number_of_coordinates>" << std::endl;
        return 1;
    }

    int num_coordinates = std::atoi(argv[1]);
    if (num_coordinates <= 0) {
        std::cerr << "Number must be positive." << std::endl;
        return 1;
    }

    Coordinate *list_beginning = nullptr;
    Coordinate *list_end = nullptr;

    std::srand(std::time(0));
    for (int i = 0; i < num_coordinates; ++i) {
        float x = static_cast<float>(std::rand() % 100);
        float y = static_cast<float>(std::rand() % 100);
        
        if (!list_beginning) {
            list_beginning = list_end = new Coordinate{x, y, i, nullptr, nullptr};
        } else {
            add_coordinate(list_end, x, y);
        }
    }

    std::cout << "displaying list forward:" << std::endl;
    forward_display(list_beginning);

    std::cout << "\ndisplaying list backward:" << std::endl;
    backward_display(list_end);

    std::cout << "\nDeleting coordinate with ID 1." << std::endl;
    delete_coordinate(list_beginning, 1);

    std::cout << "\nList after deleting:" << std::endl;
    forward_display(list_beginning);

    std::cout << "\nlist length: " << list_length(list_beginning) << std::endl;

    std::cout << "\nFinding closest to point (50, 50):" << std::endl;
    closest_to(list_beginning, 50.0f, 50.0f);

    return 0;
}

