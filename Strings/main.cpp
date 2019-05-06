#include <iostream>

#include "src/Multi_character_links.h"

#include <string>

int main() {
    Multi_character_links example("first example for you");
    Multi_character_links example1("second  example for you ");
    Multi_character_links example3;

    Multi_character_links e("");
    Multi_character_links ex("");


    change(example3, e, ex);
    example3.print();
    cout << example3 << endl;

    return 0;
}