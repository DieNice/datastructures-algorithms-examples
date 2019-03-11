//
// Created by pda on 10.03.19.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

struct Record {

    unsigned int key;

    char *data = new char[10];
};

class Hashtable {
private:

    unsigned int N; //size of table
    double k; //koaf of full 50%..80%
    unsigned int count = 0;

    struct Record *table; //vector of records

    bool *status; //status of record

    unsigned int get_hash_one(Record); //function hash 1

    unsigned int get_hash_two(unsigned int hash,unsigned int i); //function hash 2

    void rehashing(); //rehash all table and up size of table

public:
    Hashtable(unsigned int, double);

    ~Hashtable();

    bool add(Record);

    bool remove(Record);

    unsigned int search(Record);

    void print();


};

#endif //HASHTABLE_HASHTABLE_H
