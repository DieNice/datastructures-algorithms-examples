#include <iostream>

#include "src/Multi_character_links.h"

#include <string>

int main() {
    Multi_character_links example("Shit motherfucker  brother            ");

    example.print();

    Multi_character_links example2 = "My friend is alegofriend";
    Multi_character_links example3 = "My friend is niger";
    Multi_character_links example4(example2);

    Multi_character_links exp;
    cout << "kek=" << exp + example2 << endl;

    example = example2 + "hello" + "goodbye";
    cout << example.length() << endl;
    cout << example << endl;
    cout << example.substr(0, 3) << endl;
    cout << "del=" << example2.pos(example4) << endl;


    return 0;
}