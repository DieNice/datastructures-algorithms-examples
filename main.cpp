
#include <iostream>
#include "src/Permutations.h"

using namespace std;

int main() {
    unsigned int size = 0;

    cout << "Введите размер множества" << endl;
    cin >> size;

    int *array = new int[size + 1];

    cout << "Введите множество целых чисел" << endl;
    for (int i = 1; i <= size; i++) {
        cin >> array[i];
    }

    if (!check_array(array, size)) {
        Effect(array, size);
    } else cout << "Множество содержит повторяющиеся элементы!";
    return 0;
}
