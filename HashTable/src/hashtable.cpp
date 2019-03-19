#include "hashtable.h"
#include <iostream>

using namespace std;

Hashtable::Hashtable(unsigned int size, double koef) {
    N = size;
    k = koef;

    table = new struct Record[N];
    status = new bool[N];
    for (int i = 0; i < N; i++) {
        status[i] = 0;
    }
}

Hashtable::~Hashtable() {
    delete table;
    delete status;
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

double Hashtable::count_koef(int size) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (status[i] == true) { count++; }
    }

    return ((count) / (double) size) * 100; //now koef of full

}

bool Hashtable::add(Record record) {

    if ((this->search(record)) != N) { return true; }


    double k_full;
    unsigned int hash_1;

    k_full = this->count_koef(N);

    if (k_full > k) {
        inc_size();
        rehashing();
    }

    hash_1 = get_hash_one(record);

    if (status[hash_1] == !true) {
        table[hash_1].key = record.key;
        table[hash_1].data = record.data;
        status[hash_1] = true;

        return 0;
    } else {


        for (int i = 1; i < N; i++) {

            int hash_2 = get_hash_two(hash_1, i);

            if (status[hash_2] == !true) {
                table[hash_2].key = record.key;
                table[hash_2].data = record.data;
                status[hash_2] = true;
                return 0;
            }
        }
        cout << "Can't add item:" << record.key << " " << record.data << endl;
        return 1;
    }
}

bool Hashtable::remove(Record record) {
    int num = search(record);

    if (num == N) { return true; }
    status[num] = false;
    if (count_koef(N / 2) < k) {
        red_size();
    }
    rehashing();
    return 0;
}


void Hashtable::print() {

    cout << "            HashTable" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        if (status[i] == !false) {
            cout << i << ")" << table[i].key << " " << table[i].data << endl;
            cout << "----------------------------------" << endl;
        } else {
            cout << i << ") empty" << endl;
            cout << "----------------------------------" << endl;
        }
    }
}

void Hashtable::rehashing() {

    for (int i = 0; i < N; i++) {

        if (status[i] == true) {
            int hash_1 = get_hash_one(table[i]);
            if (hash_1 != i) {

                if (status[hash_1] == !true) {
                    table[hash_1].key = table[i].key;
                    table[hash_1].data = table[i].data;
                    status[hash_1] = true;
                    status[i] = false;
                } else {

                    for (int j = 1; j < N; j++) {

                        int hash_2 = get_hash_two(hash_1, j);

                        if (table[hash_2].key == table[i].key) { j = N; }
                        else {

                            if (status[hash_2] == !true) {
                                table[hash_2].key = table[i].key;
                                table[hash_2].data = table[i].data;
                                status[hash_2] = true;
                                status[i] = false;
                            }
                        }
                    }

                }


            }
        }
    }
}

unsigned int Hashtable::search(Record record) {
    unsigned int hash_1;
    hash_1 = get_hash_one(record);
    if (status[hash_1] == true) {
        if (table[hash_1].key == record.key) {
            return hash_1;
        }
    }
    //if nщt found by hash_1
    for (int i = 1; i < N; i++) {

        int hash_2 = get_hash_two(hash_1, i);

        if (status[hash_2] == true) {
            if (table[hash_2].key == record.key) {
                return hash_2;
            }
        }
    }
    return N;//null string of table
}

void Hashtable::inc_size() {
    struct Record *table_buf = new struct Record[N * 2];
    bool *status_buf = new bool[N * 2];

    for (int i = 0; i < N; i++) {
        table_buf[i] = table[i];
        status_buf[i] = status[i];
    }
    delete[] table;
    table = table_buf;
    delete[] status;
    status = status_buf;
    N = N * 2;
}

void Hashtable::red_size() {
    struct Record *table_buf = new struct Record[N / 2];
    bool *status_buf = new bool[N / 2];

    for (int i = 0; i < N; i++) {
        table_buf[i] = table[i];
        status_buf[i] = status[i];
    }
    delete[] table;
    table = table_buf;
    delete[] status;
    status = status_buf;
    N = N / 2;
}