#include <iostream>

#include "src/Multi_character_links.h"

#include <string>

int main() {
    Multi_character_links example("first example for you");
    Multi_character_links example1("first  example for you ");
/*
    example.print();
    example1.print();
*/


    Multi_character_links e("  ");
    Multi_character_links ex("Hueva tutueva");

    example = example + example1;
    example.print();
    change(example, e, ex);
    example.print();
    cout << example << endl;

    return 0;
}