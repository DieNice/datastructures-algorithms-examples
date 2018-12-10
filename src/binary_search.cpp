#include <iostream>
using namespace std;
// функция двоичного поиска
int Search_Binary(int A[], int N, int key) {
  int m = 0;     //середина вектора
  int l = 0;     //нижняя граница
  int u = N - 1; //верхняя границв
  while (l <= u) {
    int m = (l + u) / 2;
    if (A[m] > key) {
      u = m - 1;
    } else if (A[m] < key) {
      l = m + 1;
    } else {
      if (A[m] == key)
        return m;
    }
  }
  return -1;
}
