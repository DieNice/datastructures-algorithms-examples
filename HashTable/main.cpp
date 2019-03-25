#include <iostream>
#include "src/hashtable.h"
#include <string>

using namespace std;

int main() {
        Hashtable table(5, 80);
        Record record;
        record.key = 810000;
        record.data = "PDA";
    unsigned char k;
        for (int i = 1; i < 3; i++) {
          k=  table.add(record);
            if (k) cout <<"ERROR"<<endl;
            record.key += 2;
            record.data[2]++;

        }



        table.print();

    for (int i = 0; i < 3; i++) {
        table.remove(record);
        record.key -= 2;
        record.data[2]--;

    }



        table.print();

    return 0;
}