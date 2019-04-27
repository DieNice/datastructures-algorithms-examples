//
// Created by pda on 21.04.19.
//

#ifndef STRINGS_MULTI_CHARACTER_LINKS_H
#define STRINGS_MULTI_CHARACTER_LINKS_H

#include <iostream>

using namespace std;

struct Link {
    char *data;
    Link *Next, *Prev;
};

class Multi_character_links {
private:
    Link *Head, *Tail;

    void add_elem(char *const data, unsigned int size);

public:
    Multi_character_links() : Head(nullptr), Tail(nullptr) {
    };

    Multi_character_links(const Multi_character_links &obj);

    Multi_character_links(const char *const data);

    ~Multi_character_links();

    friend std::ostream &operator<<(std::ostream &out, const Multi_character_links &obj);

    Multi_character_links &operator=(Multi_character_links &data);

    Multi_character_links &operator=(const char *const data);

    Multi_character_links &operator+(Multi_character_links &data);

    Multi_character_links &operator+(const char *const data);

    unsigned int length();

    int pos(Multi_character_links sub);

    Multi_character_links substr(unsigned int k, unsigned int n);

    Multi_character_links del(unsigned int k, unsigned int n);

    void print();
};


#endif //STRINGS_MULTI_CHARACTER_LINKS_H
