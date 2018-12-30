#include <iostream>
using namespace std;

int sw = 0;
int eq = 0;

void ShellSort(int *A, int n) //сортировка Шелла
{
  int i, j, d, count;

  d = n;
  d = d / 2;
  while (d > 0) {
    for (i = 0; i < n - d; i++) {
      j = i;
      eq++;
      while (j >= 0 && A[j] > A[j + d]) {
        count = A[j];
        A[j] = A[j + d];
        A[j + d] = count;
        sw++;
        eq++;
        j--;
      }
    }
    d = d / 2;
  }
  cout << "swap=" << sw << endl;
  cout << "eq=" << eq << endl;
}
