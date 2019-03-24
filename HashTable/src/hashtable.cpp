#include "hashtable.h"
#include <iostream>

using namespace std;

Hashtable::Hashtable(unsigned int size, double koef) {
    N = size;
    k = koef;

    if (N <= min_size) { throw UNCCORECT_SIZE; }
    if (k < min_k || k > max_k) { throw UNCCORECT_KOEF; }

    table = new struct Record[N];
    status = new bool[N];
    for (int i = 0; i < N; i++) {
        status[i] = false;
    }

}

Hashtable::~Hashtable() {
    if (N > min_size && (k >= min_k && k <= max_k)) {
        delete[] table;
        delete[] status;
    }
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

    if (record.key < min_key || record.key > max_key) { throw UNCCRORECT_KEY; }
    if ((search(record)) != N) { throw RECORD_EXISTS; }


    double k_full;
    unsigned int hash_1;

    k_full = count_koef(N);

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
        throw HASH_CANT;
    }
}

bool Hashtable::remove(Record record) {

    int num = search(record);
    if (num == N) { throw RECORD_NOT_EXISTS; }

    status[num] = false;
    double k_empty = count_koef(N / 2);

    if (k_empty < k) {
        red_size();
    } else rehashing();

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
    struct Record *table_result = new struct Record[N / 2];
    bool *status_result = new bool[N / 2];

    for (int i = 0; i < N / 2; i++) { status_result[i] = false; }

    struct Record *table_buf = new struct Record[N];
    bool *status_buf = new bool[N];

    for (int i = 0; i < N; i++) {
        table_buf[i] = table[i];
        status_buf[i] = status[i];
    }
    delete[] table;
    table = table_result;
    delete[] status;
    status = status_result;

    unsigned int old_size = N;
    N = N / 2;

    for (int i = 0; i < old_size; i++) {
        if (status_buf[i] != false) {
            this->add(table_buf[i]);
        }
    }
    delete[] table_buf;
    delete[] status_buf;


}
