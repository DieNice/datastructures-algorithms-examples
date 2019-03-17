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
    double k; //koefficient of full 50%..80%

    struct Record *table; //vector of records

    bool *status; //status of record

    unsigned int get_hash_one(Record); //function hash 1 +

    unsigned int get_hash_two(unsigned int, unsigned int); //function hash 2 +

    double count_koef();//count coefficient of full +

    void inc_size();//increase size of table

    void red_size();//reduce size of table

    void rehashing(); //rehash all table and up size of table +

public:
    Hashtable(unsigned int, double);//+

    ~Hashtable();//+

    bool add(Record);//+-

    bool remove(Record);//+-

    unsigned int search(Record);//+

    void print();//+


};

#endif //HASHTABLE_HASHTABLE_H
