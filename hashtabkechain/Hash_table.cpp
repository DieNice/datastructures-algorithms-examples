//
// Created by pda on 16.10.19.
//

#include "Hash_table.h"

Record::Record(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) {
    shtraf = a;
    number_avto = b;
    day = c;
    month = d;
    year = e;
    over = nullptr;
}

Record::Record() {
    over = nullptr;
}

bool operator==(Record const &record1, Record const &record2) {
    return record1.day == record2.day
           && record1.year == record2.year
           && record1.month == record2.month
           && record1.shtraf == record2.shtraf
           && record1.number_avto == record2.number_avto;
}

/*------------------------------------HashTable-----------*/


unsigned int Hash_table::getHash(Record record) {
    return record.shtraf + record.number_avto + record.year + record.month + record.day;
}


Hash_table::Hash_table(unsigned int n) {
    const int DEF = 10;

    if (n == 0) { sizetable = DEF; }
    else { sizetable = n; }

    data = new Record[sizetable];
    status = new bool[sizetable];
    count_of_added = 0;

    for (int i = 0; i < sizetable; ++i) {
        status[i] = false;
    }
}

Hash_table::~Hash_table() {
    delete[] data;
    delete[] status;
}


bool Hash_table::search(Record record) {
    unsigned int pos = getHash(record) % sizetable;
    if (data[pos] == record) {
        return true;
    } else {
        if (data[pos].over == nullptr) { return false; }
        Record *nowptr = data[pos].over;

        while (nowptr != nullptr) {
            if (*nowptr == record) { return true; }
            nowptr = nowptr->over;
        }
        return false;
    }
}

bool Hash_table::addRecChain(Record &myrec, unsigned int &pos) {
    unsigned int hashadd = getHash(myrec);
    unsigned int nowhash = getHash(data[pos]);

    if (hashadd >= nowhash) {
        Record *bufrec = new Record;
        *bufrec = data[pos];
        myrec.over = bufrec;
        data[pos] = myrec;
        count_of_added++;
    } else {
        Record *nowptr = &data[pos];

        bool flag = false;

        while (!flag) {

            if (nowptr->over == nullptr) {
                nowptr->over = &myrec;
                count_of_added++;
                flag = true;

            } else {
                nowhash = getHash(*nowptr->over);
                if (hashadd >= nowhash) {
                    Record *bufptr = nowptr->over;
                    nowptr->over = &myrec;
                    myrec.over = bufptr;
                    flag = true;
                    count_of_added++;

                }
                nowptr = nowptr->over;
            }
        }

    }


}

int Hash_table::add(Record &record) {
    if (search(record)) { return -1; }

    unsigned int posrec = getHash(record) % sizetable;
    if (!status[posrec]) {
        data[posrec] = record;
        count_of_added++;
        status[posrec] = true;
    } else {
        addRecChain(record, posrec);
    }
}


int Hash_table::remove(Record &record) {
    if (!search(record)) { return -1; }

    unsigned int posrec = getHash(record) % sizetable;
    if (data[posrec] == record) {
        data[posrec].day = data[posrec].over->day;
        data[posrec].month = data[posrec].over->month;
        data[posrec].year = data[posrec].over->year;
        data[posrec].shtraf = data[posrec].over->shtraf;
        data[posrec].number_avto = data[posrec].number_avto;
        data[posrec].over = data[posrec].over->over;
        count_of_added--;
    } else {
        Record *nowptr = &data[posrec];
        Record *slowptr = &data[posrec];
        bool flag = false;
        while (!flag) {
            nowptr = nowptr->over;
            if (*nowptr == record) {
                if (nowptr->over == nullptr) {
                    slowptr->over = nullptr;
                    count_of_added--;
                    flag = true;
                } else {
                    nowptr->number_avto = nowptr->over->number_avto;
                    nowptr->shtraf = nowptr->over->shtraf;
                    nowptr->day = nowptr->over->day;
                    nowptr->month = nowptr->over->month;
                    nowptr->year = nowptr->over->year;

                    Record *onceptr = nowptr->over->over;
                    delete nowptr->over->over;
                    nowptr->over = onceptr;
                    delete onceptr;
                    count_of_added--;
                    flag = true;
                }

            }
            slowptr = nowptr;
        }

    }

}

std::ostream &operator<<(std::ostream &out, Hash_table &point) {
    out << "-----------------begin table----------------" << std::endl;
    for (int i = 0; i < point.sizetable; i++) {
        if (point.status[i]) {
            out << i << ":";
            out << "Штраф=";
            out << point.data[i].shtraf << "; Номер авто=";
            out << point.data[i].number_avto << "; День=";
            out << point.data[i].day << "; Месяц";
            out << point.data[i].month << "; Год=";
            out << point.data[i].year << ";";

            if (point.data[i].over != nullptr) {
                Record *nowptr = point.data[i].over;
                while (nowptr != nullptr) {
                    out << "<--";
                    out << "Штраф=";
                    out << nowptr->shtraf << "; Номер авто=";
                    out << nowptr->number_avto << "; День=";
                    out << nowptr->day << "; Месяц=";
                    out << nowptr->month << "; Год=";
                    out << nowptr->year << ";";
                    nowptr = nowptr->over;
                }
                delete nowptr;
            }
            out << std::endl;
        }

    }
    out << "-----------------end table----------------" << std::endl;
    return out;
}


Hash_table::Hash_table(const Hash_table &object) {
    this->sizetable = object.sizetable;
    data = new Record[sizetable];
    status = new bool[sizetable];
    count_of_added = 0;

    for (int i = 0; i < sizetable; i++) {
        status[i] = object.status[i];
    }

    for (int i = 0; i < sizetable; i++) {
        data[i] = object.data[i];
        if (object.data[i].over != nullptr) {
            Record *nowptr = object.data[i].over;
            while (nowptr != nullptr) {
                Record *bufrec = new Record;
                *bufrec = *nowptr;
                this->add(*bufrec);
                nowptr = nowptr->over;
            }
        }
    }

}

Hash_table &Hash_table::operator=(Hash_table const &object) {
    Hash_table *result = new Hash_table(this->sizetable);

    delete[] this->data;
    delete[] this->status;

    data = new Record[sizetable];
    status = new bool[sizetable];
    count_of_added = 0;


    for (int i = 0; i < object.sizetable; i++) {
        if (object.status[i]) {
            add(object.data[i]);
            result->add(object.data[i]);
            if (object.data[i].over != nullptr) {
                Record *nowptr = object.data[i].over;
                while (nowptr != nullptr) {
                    Record *bufrec = new Record;
                    *bufrec = *nowptr;
                    this->add(*bufrec);
                    result->add(*bufrec);
                    nowptr = nowptr->over;
                }
            }
        }
    }

    return *result;

}

Hash_table &Hash_table::operator+(const Hash_table &right) {

    Hash_table *result = new Hash_table(this->sizetable);

    for (int i = 0; i < right.sizetable; i++) {
        if (right.status[i]) {
            result->add(right.data[i]);
            if (right.data[i].over != nullptr) {
                Record *nowptr = right.data[i].over;
                while (nowptr != nullptr) {
                    Record *bufrec = new Record;
                    *bufrec = *nowptr;
                    result->add(*bufrec);
                    nowptr = nowptr->over;
                }
            }
        }
    }
    return *result;
}

Hash_table &Hash_table::operator+(const Record &right) {
    Hash_table *result = this;
    result->add(const_cast<Record &>(right));
    return *result;
}