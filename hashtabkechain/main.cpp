#include <iostream>

#include "Hash_table.h"

using namespace std;

int main() {
    Record record(15, 14, 13, 12, 15);
    Record record1(15, 14, 13, 11, 16);
    Record record2(15, 13, 14, 12, 15);
    Record record3(150, 13, 29, 12, 15);
    Record record4(150, 13, 29, 12, 15);
    Hash_table hashTable(30);
    hashTable.add(record1);
    hashTable.add(record3);
    hashTable.add(record);
    hashTable.add(record2);
    cout << hashTable.add(record4) << endl;
    cout << hashTable;


    Hash_table hashTable1(8);
    Hash_table hashTable2(5);

    hashTable2 = hashTable1 = hashTable;

    cout << hashTable1;
    cout << hashTable2;

    Hash_table hashTable3 = hashTable1 + hashTable2;
    cout << hashTable3;

    Record record5(100, 100, 100, 100, 100);
    cout << hashTable2 + record5;
    hashTable2.remove(record4);
    hashTable2.remove(record1);
    cout << hashTable2;
    return 0;
}