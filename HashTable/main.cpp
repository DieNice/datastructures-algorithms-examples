#include <iostream>
#include "src/hashtable.h"

using namespace std;

int main() {
    Hashtable example(10, 50);
    Record a;
    a.key = 350000;
    a.data = (char *) "PDA";

    for (int i = 1; i < 10; i++) {
        example.add(a);
        a.key += 2;
        a.data[2]++;

    }

    example.print();

    a.key = 350000;
    a.data = (char *) "PDA";

    for (int i = 1; i < 5; i++) {
        example.remove(a);
        a.key += 2;
        a.data[2]++;

    }

    example.print();


    a.key = 350000;
    a.data = (char *) "PDA";

    for (int i = 1; i < 10; i++) {
        example.add(a);
        a.key += 2;
        a.data[2]++;

    }

    example.print();

    return 0;
}