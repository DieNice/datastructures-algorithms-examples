#include "src/sort_lib.h"
#include <iostream>
#include <time.h>
using namespace std;
int main() {
  clock_t start, stop; //время работы сортировки
  int size_array;      //размерность массива
  cout << "Введите размерность массива=";
  cin >> size_array;
  int a[size_array];
  int b[size_array];
  // Заполнение массива случайными числами
  for (int i = 0; i < size_array; i++) {
    a[i] = rand() % size_array + 1;
    b[i] = a[i];
  }
  // Вывод элементов массива до сортировки
  for (int i = 0; i < size_array; i++)
    printf("%d ", a[i]);
  printf("\n");
  cout << "Пиромидальная сортировка" << endl;
  start = clock();
  heapSort(a, size_array); // вызов функции сортировки
  stop = clock();
  // Вывод элементов массива после сортировки
  for (int i = 0; i < size_array; i++)
    printf("%d ", a[i]);
  printf("\n");
  cout << "HeapSort Time Spend: " << (stop - start) / 1000.0 << "ms"
       << std::endl;
  cout << "Сортировка Шелла" << endl;
  start = clock();
  ShellSort(b, size_array);
  stop = clock();
  // Вывод элементов массива после сортировки
  /*for (int i = 0; i < size_array; i++)
    printf("%d ", b[i]);
  printf("\n");*/
  cout << "ShellSort Time Spend: " << (stop - start) / 1000.0 << "ms"
       << std::endl;
  return 0;
}
