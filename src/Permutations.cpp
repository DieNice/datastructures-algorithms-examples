#include <iostream>
#include <set>

using namespace std;

void Effect(set<int> mySet, int size) {
    int *z, *p, *d;
    unsigned int k;
    int pm, dm, zpm;
    int i, m, w;

    int arr[mySet.size()];//массив с элементами множества

    set<int>::iterator it = mySet.begin();
    for (int i = 0; i < mySet.size(); i++) {
        arr[i] = *it;
        it++;
    }

    z = (int *) malloc((size + 2) * sizeof(int)); //перестановка
    p = (int *) malloc((size + 2) * sizeof(int)); //обратная
    d = (int *) malloc((size + 2) * sizeof(int)); //Смещение

    for (i = 1; i <= size; i++) {
        z[i] = p[i] = i;
        d[i] = -1;
    }
    d[1] = 0;
    z[0] = z[size + 1] = m = size + 1; //метки границы
    k = 0;//счётчик числа перестановок

    //printf permutations
    while (m != 1) {
        k++;
        cout << "\n" << k << ")";

        for (i = 1; i <= size; i++) { cout << arr[z[i] - 1]; }//
        m = size;
        while (z[p[m] + d[m]] > m) {
            d[m] = -d[m];
            m--;
        }
        pm = p[m];
        dm = pm + d[m];
        w = z[pm];
        z[pm] = z[dm];
        z[dm] = w;
        zpm = z[pm];
        w = p[zpm];
        p[zpm] = pm;
        p[m] = w;
    }
    free(z);
    free(p);
    free(d);
}