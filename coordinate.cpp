#include <iostream>
#include <cmath>
#include <limits>
#include "coordinate.h"

static int current_id = 0;
void add_coordinate(Coordinate *&list_end, float x, float y) {
    Coordinate *new_coord = new Coordinate();
    new_coord->x = x;
    new_coord->y = y;
    new_coord->coord_id = current_id++;
    new_coord->next = nullptr;
    new_coord->previous = list_end;

    if (list_end) {
        list_end->next = new_coord;
    }
    list_end = new_coord;
}
void forward_display(Coordinate *list_beginning) {
    Coordinate *current = list_beginning;
    while (current) {
        std::cout << "ID: " << current->coord_id << ", X: " << current->x << ", Y: " << current->y << std::endl;
        current = current->next;
    }
}

void backward_display(Coordinate *list_end) {
    Coordinate *current = list_end;
    while (current) {
        std::cout << "ID: " << current->coord_id << ", X: " << current->x << ", Y: " << current->y << std::endl;
        current = current->previous;
    }
}
void delete_coordinate(Coordinate *&list_beginning, int coord_id_to_delete) {
    Coordinate *current = list_beginning;
    while (current && current->coord_id != coord_id_to_delete) {
        current = current->next;
    }

    if (!current) return;

    if (current->previous) {
        current->previous->next = current->next;
    } else {
        list_beginning = current->next;
    }

    if (current->next) {
        current->next->previous = current->previous;
    }

    delete current;
}

int list_length(Coordinate *list_beginning) {
    int length = 0;
    Coordinate *current = list_beginning;
    while (current) {
        length++;
        current = current->next;
    }
    return length;
}

void closest_to(Coordinate *list_beginning, float x, float y) {
    Coordinate *current = list_beginning;
    Coordinate *closest = nullptr;
    float min_distance = std::numeric_limits<float>::max();
    while (current) {
        float distance = std::sqrt((current->x - x) * (current->x - x) + (current->y - y) * (current->y - y));
        if (distance < min_distance) {
            min_distance = distance;
            closest = current;
        }
        current = current->next;
    }

    if (closest) {
        std::cout << "closest coordinate to (" << x << ", " << y << ") is ID: " << closest->coord_id
                  << " at (" << closest->x << ", " << closest->y << ") with distance " << min_distance << std::endl;
    }
}

