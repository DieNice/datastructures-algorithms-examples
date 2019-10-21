//
// Created by pda on 16.10.19.
//

#ifndef HASHTABKECHAIN_HASH_TABLE_H
#define HASHTABKECHAIN_HASH_TABLE_H

#include <ostream>
#include <iostream>

struct Record {
    unsigned int shtraf;
    unsigned int number_avto;
    unsigned int day;
    unsigned int month;
    unsigned int year;
    Record *over;

    Record();

    Record(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);


};


/*--------Class HashTable with chain of full----------*/

class Hash_table {

private:
    Record *data;
    bool *status;
    unsigned int sizetable;
    int count_of_added;

    void initialize(unsigned int);
    unsigned int getHash(Record);

    bool search(Record);

    bool addRecChain(Record &, unsigned int &);


public:

    Hash_table(unsigned int);

    Hash_table(const Hash_table &);

    ~Hash_table();

    int add(Record &record);

    int remove(Record &record);

    Hash_table &operator=(Hash_table const &object);

    Hash_table &operator+(const Hash_table &right);

    Hash_table &operator+(const Record &right);

    friend std::ostream &operator<<(std::ostream &out, Hash_table &point);
};

#endif //HASHTABKECHAIN_HASH_TABLE_H
