#include "hashtable.h"
#include <iostream>

using namespace std;

Hashtable::Hashtable(unsigned int size, double kof) {
    N = size;
    k = kof;
    table = new struct Record[N];
    status = new bool[N];
    for (int i = 0; i < N; i++) {
        status[i] = 0;
    }
}

Hashtable::~Hashtable() {

}


unsigned int Hashtable::get_hash_one(Record record) {

    const int ten = 10;

    unsigned int key = record.key;
    unsigned int result = 0;

    while (key != 0) {
        result = result + key % ten;
        key = key / ten;
    }

    return (result % N);
}


unsigned int Hashtable::get_hash_two(unsigned int hash, unsigned int i) {

    return (hash + i * i) % N;
}

bool Hashtable::add(Record record) {
    double k_full;
    unsigned int hash_1;

    k_full = ((count + 1) / (double) N) * 100; //now kof of full

    if (k_full > k) {
        //rehashing();
    }

    hash_1 = get_hash_one(record);

    if (status[hash_1] == !true) {
        table[hash_1].key = record.key;
        table[hash_1].data = record.data;
        status[hash_1] = true;
        count++;

        return 0;
    } else {


        for (int i = 1; i < N; i++) {

            int hash_2 = get_hash_two(hash_1, i);

            if (status[hash_2] == !true) {
                table[hash_2].key = record.key;
                table[hash_2].data = record.data;
                status[hash_2] = true;
                count++;

                return 0;
            }
        }
        cout << "Can't add item:" << record.key << " " << record.data << endl;
        return 1;
    }
}

void Hashtable::print() {

    cout << "            HashTable" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        if (status[i] == !0) {
            cout << i << ")" << table[i].key << " " << table[i].data << endl;
            cout << "----------------------------------" << endl;
        } else {
            cout << i << ") empty" << endl;
            cout << "----------------------------------" << endl;
        }
    }
}

void Hashtable::rehashing() {}