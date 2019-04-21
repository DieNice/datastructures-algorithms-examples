//
// Created by pda on 21.04.19.
//

#ifndef STRINGS_MULTI_CHARACTER_LINKS_H
#define STRINGS_MULTI_CHARACTER_LINKS_H

struct Link {
    char *data;
    Link *Next, *Prev;
};

class Multi_character_links {
private:
    Link *Head, *Tail;

    unsigned int len;//num of links

    unsigned int len_all;//num of char

public:
    Multi_character_links() : Head(nullptr), Tail(nullptr) {
        len = 0;
    };

    Multi_character_links(const Multi_character_links &obj);

    ~Multi_character_links();

    unsigned int print();

    int pos(Multi_character_links sub, Multi_character_links s);

    Multi_character_links substr(Multi_character_links s, unsigned int k, unsigned int n);

    Link read();

    unsigned int length();

    Multi_character_links &operator=(Multi_character_links data);

    Multi_character_links &operator=(char *const data);

    Multi_character_links &operator+(Multi_character_links data);

    Multi_character_links &operator+(char *const data);


};


#endif //STRINGS_MULTI_CHARACTER_LINKS_H
