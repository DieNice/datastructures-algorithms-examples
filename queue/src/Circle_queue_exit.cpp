//
// Created by pda on 07.04.19.
//
#include <iostream>

#include "Circle_queue_exit.h"

Circle_queue_exit::Circle_queue_exit(unsigned int size) {
    const int def_size = 10;
    const int one = 1;

    if (size <= one) {
        max_l = def_size;
    } else { max_l = size; }

    vector = new struct element[max_l + one];
    left = 0;
    right = max_l + one;

}

Circle_queue_exit::~Circle_queue_exit() {
    delete[] vector;
}


unsigned int Circle_queue_exit::add(element el) {
    //add fist element
    if (left == 0 && right == max_l + 1) {
        right = left;
        vector[right].priority = el.priority;
        vector[right].data = el.data;
    } else {
        if (length() == max_l) { return 1; }
        right++;
        vector[(right + max_l) % max_l].data = el.data;
        vector[(right + max_l) % max_l].priority = el.priority;
    }
    return 0;
}

unsigned int Circle_queue_exit::print() {
    if (length() == 0) { return 2; }//queue empty
    for (int i = left; i <= right; i++) {
        std::cout << vector[(i + max_l) % max_l].priority << "|" << vector[(i + max_l) % max_l].data << std::endl;

    }
}

unsigned int Circle_queue_exit::length() {
    if (right - left + 1 > max_l) { return 0; }
    return (right - left + 1);
}

unsigned int Circle_queue_exit::del() {

    if (length() == 0) { return 2; }//queue empty


    if (length() == 1) {
        left = 0;
        right = max_l;
    } else {
        int num_priority = left;

        for (int i = left; i <= right; i++) {
            if (vector[(i + max_l) % max_l].priority > vector[num_priority].priority) {
                num_priority = i;
            }
        }
        if (num_priority > (left + right) / 2) { move_left(num_priority); }
        else { move_right(num_priority); }
    }
    return 0;

}

element Circle_queue_exit::read(unsigned int deep) {
    if (length() == 0) {
        element empty;
        empty.data = "empty";
        empty.priority = 0;
        return empty;
    }

    struct element *buf = new struct element[max_l + 1];

    for (int i = 0; i < max_l; i++) { buf[i] = vector[i]; }

    deep = deep % length();
    for (int j = 0; j < deep; j++) {
        del();
    }

    int num_priority = left;

    for (int i = left; i <= right; i++) {
        if (vector[(i + max_l) % max_l].priority > vector[num_priority].priority) {
            num_priority = i;
        }
    }
    for (int i = 0; i < max_l; i++) { vector[i] = buf[i]; }
    delete[] buf;
    return vector[num_priority];

}

void Circle_queue_exit::move_left(const unsigned int pos) {
    for (int i = 0; i < right - pos; i++) {
        vector[i + pos] = vector[i + pos + 1];
    }
    right = right - 1;

}

void Circle_queue_exit::move_right(const unsigned int pos) {
    for (int i = 0; i < pos - left; i++) {
        vector[pos - i] = vector[pos - i - 1];
    }
    left = left + 1;

}

Circle_queue_exit::Circle_queue_exit(const Circle_queue_exit &obj) {
    max_l = obj.max_l;
    vector = new struct element[max_l + 1];
    for (int i = 0; i < max_l + 1; i++) {
        vector[i] = obj.vector[i];
    }
    right = obj.right;
    left = obj.left;
}

void Circle_queue_exit::operator=(Circle_queue_exit &obj) {
    if (obj.max_l <= max_l) {
        for (int i = 0; i <= obj.max_l; i++) {
            vector[i] = obj.vector[i];
        }
        left = obj.left;
        right = obj.right;
    } else {
        for (int i = obj.left; i < max_l + obj.left; i++) {
            vector[i - obj.left] = obj.vector[i];
        }
        left = 0;
        right = max_l - 1;

    }
}