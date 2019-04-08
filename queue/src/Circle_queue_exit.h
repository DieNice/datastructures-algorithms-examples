//
// Created by pda on 07.04.19.
//

#ifndef QUEUE_CIRCLE_QUEUE_EXIT_H
#define QUEUE_CIRCLE_QUEUE_EXIT_H

#include <string>

using namespace std;

struct element {
    int priority;
    string data;

};

class Circle_queue_exit {
private:
    struct element *vector;
    unsigned int max_l;
    unsigned int right, left;

    void move_left(const unsigned int pos);

    void move_right(const unsigned int pos);

public:
    Circle_queue_exit(unsigned int size);

    Circle_queue_exit(const Circle_queue_exit &obj);

    ~Circle_queue_exit();

    unsigned int add(element);

    unsigned int del();

    element read();

    unsigned int length();

    unsigned int print();

    void operator =(Circle_queue_exit&);


};


#endif //QUEUE_CIRCLE_QUEUE_EXIT_H
