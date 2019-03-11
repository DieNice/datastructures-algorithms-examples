#include <iostream>
#include "src/hashtable.h"

int main() {
    Hashtable example(10, 30);
    Record a;
    a.key = 350619;
    a.data = (char *) "PDA";
    Record b;
    b.key = 350619;
    b.data = (char *) "PDA1";
    Record c;
    c.key = 350619;
    c.data = (char *) "PDA2";
    Record d;
    d.key = 350619;
    d.data = (char *) "PDA3";
    example.add(a);
    example.add(b);
    example.add(c);
    example.add(d);
    example.print();
    return 0;
}