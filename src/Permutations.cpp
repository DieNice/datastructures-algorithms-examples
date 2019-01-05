#include <iostream>

using namespace std;

bool check_array(int *Array, int size) {
    bool flag = false;

    for (int i = 1; i < size; i++) {
        for (int j = i + 1; j <= size; j++) {
            if (Array[i] == Array[j]) {
                flag = true;
                i = size;
                j = i + 1;
            }
        }
    }
    return flag;
};

void Effect(int *vector, int size) {
    int *z, *p, *d;
    unsigned int k;
    int pm, dm, zpm;
    int i, m, w;

    z = (int *) malloc((size + 2) * sizeof(int)); //перестановка
    p = (int *) malloc((size + 2) * sizeof(int)); //обратная
    d = (int *) malloc((size + 2) * sizeof(int)); //Смещение

    for (i = 1; i <= size; i++) {
        z[i] = p[i] = i;
        d[i] = -1;
    }
    d[1] = 0;
    z[0] = z[size + 1] = m = size + 1;
    k = 0;

    //printf permutations
    while (m != 1) {
        k++;
        cout << "\n" << k<<")";
        for (i = 1; i <= size; i++) { cout << z[i]; }
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