#include <iostream>

#include "src/Multi_character_links.h"

int main() {
    Multi_character_links example("Shit motherfucker  brother            ");

    example.print();

    Multi_character_links example2 = "My friend is alegofriend";
    example2.print();
    example =  example2 + "hui";
    example.print();


    return 0;
}