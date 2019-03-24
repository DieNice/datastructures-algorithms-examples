//
// Created by pda on 10.03.19.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <string>

enum errors {
    UNCCORECT_SIZE = 1, UNCCORECT_KOEF, UNCCRORECT_KEY, RECORD_EXISTS, HASH_CANT, RECORD_NOT_EXISTS
};

struct Record {

    unsigned int key;

    std::string data;
};

class Hashtable {
private:
    const char max_k = 80;
    const char min_k = 60;
    const char min_size = 1;
    const unsigned int min_key = 100000;
    const unsigned int max_key = 999999;

    unsigned int N; //size of table

    double k; //koefficient of full 60%..80%

    struct Record *table; //vector of records

    bool *status; //status of record

    unsigned int get_hash_one(Record); //function hash 1

    unsigned int get_hash_two(unsigned int, unsigned int); //function hash 2

    double count_koef(int);//count coefficient of full

    void inc_size();//increase size of table

    void red_size();//reduce size of table and rehashing table

    void rehashing(); //rehash all table

public:
    Hashtable(unsigned int, double);

    ~Hashtable();

    bool add(Record);

    bool remove(Record);

    unsigned int search(Record);

    void print();


};

#endif //HASHTABLE_HASHTABLE_H
