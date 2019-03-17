#include <iostream>
#include "src/hashtable.h"

using namespace std;

int main() {
    Hashtable example(10, 30);
    Record a;
    a.key = 350629;
    a.data = (char *) "PDA";
    Record b;
    b.key = 355619;
    b.data = (char *) "PDA1";
    Record c;
    c.key = 351219;
    c.data = (char *) "PDA2";
    Record d;
    d.key = 350419;
    d.data = (char *) "PDA3";
    example.add(a);
    example.add(b);
    example.add(c);
    example.add(d);

    Record e;
    e.key = 530419;
    e.data = (char *) "PDA4";
    example.add(e);
    example.print();
/*    cout << example.search(a) << endl;
    cout << example.search(b) << endl;
    cout << example.search(c) << endl;
    cout << example.search(d) << endl;
    cout << example.search(e) << endl;*/
    example.remove(e);
    example.print();
    return 0;
}