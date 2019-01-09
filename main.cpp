#include <iostream>
#include "src/Permutations.h"
#include <set>
#include <fstream>

using namespace std;

int main() {
    set<int> mySet;//пустое множество

    ifstream file("/home/denis/git/DSA/input.txt");

    if (file.is_open()) {
        cout << "Файл открыт!";

        while (!file.eof()) {
            int buf;
            file >> buf;
            mySet.insert(buf);
        }

        if (mySet.size() != 0) {
            Effect(mySet, mySet.size());
        } else {
            cout << "Множество пустое!";
            return -1;
        }
    } else {
        cout << "Файл не открыт!" << endl;
        return -1;
    }

    return 0;
}
