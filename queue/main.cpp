#include <iostream>
#include "src/Circle_queue_exit.h"


int main() {
    Circle_queue_exit example(5);

    element rec;
    rec.data = "A";
    cout << "Length=" << example.length() << endl;
    for (int i = 0; i < 5; i++) {
        rec.priority = 5 - i;
        cout << "code=" << example.add(rec) << endl;
        rec.data[0]++;
    }
     cout << "Length=" << example.length() << endl;
     example.print();
     for (int i = 0; i < 5; i++) {
         example.del();
     }

     cout << "Length=" << example.length() << endl;
     example.print();
     cout << example.read(3).data << endl;

    Circle_queue_exit example2(10);

    for (int i = 0; i < 10; i++) {
        rec.priority = 10 - i;
        cout << "code=" << example2.add(rec) << endl;
        rec.data[0]++;
    }
    example2.print();
    cout << "-------" << endl;
    example.print();
    cout << "-------" << endl;
    example = example2;
    example.print();
    return 0;
}