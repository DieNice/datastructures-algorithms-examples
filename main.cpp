#include <iostream>
#include "src/sort_lib.h"
#include <time.h>

int main() {
    clock_t start,stop;
    long int size_array;
    std::cin >> size_array;


    long int a[size_array];
    // Заполнение массива случайными числами
    for (long int i = 0; i<size_array; i++)
        a[i] = rand()  % size_array+1;
    // Вывод элементов массива до сортировки
    for (long int i = 0; i<size_array; i++)
        printf("%d ", a[i]);
    printf("\n");
    start = clock();
    heapSort(a, size_array); // вызов функции сортировки
    stop = clock();
    // Вывод элементов массива после сортировки
    for (long int i = 0; i<size_array; i++)
        printf("%d ", a[i]);
    printf("\n");

    std::cout  << std::endl <<  "HeapSort Time Spend: " << (stop-start)/1000.0 << "ms" << std::endl;

    getchar();
    return 0;
}