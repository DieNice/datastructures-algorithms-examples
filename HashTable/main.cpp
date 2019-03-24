#include <iostream>
#include "src/hashtable.h"
#include <string>

using namespace std;

int main() {
    try {
        Hashtable table(10, 80);
        Record record;
        record.key = 350600;
        record.data = "PDA";
        for (int i = 1; i < 5; i++) {
            table.add(record);
            record.key += 2;
            record.data[2]++;

        }
        record.key = 530606;
        record.data = "NEW_PDD";
        table.add(record);
        table.print();

        record.key = 350606;
        record.data = "PDD";
        table.remove(record);
        table.print();


    }
    catch (errors err) {
        cout << "Error#" << err << endl;
    }

    return 0;
}