#include "sort_lib.h"
#include <stdio.h>
#include <stdlib.h>

// Функция "просеивания" через кучу - формирование кучи
void siftDown(long int *numbers, long int root, long int bottom)
{
    long int maxChild; // индекс максимального потомка
    long int done = 0; // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)    // если мы в последнем ряду,
            maxChild = root * 2;    // запоминаем левый потомок
            // иначе запоминаем больший потомок из двух
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
        if (numbers[root] < numbers[maxChild])
        {
            long int temp = numbers[root]; // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else // иначе
            done = 1; // пирамида сформирована
    }
}

// Функция сортировки на куче
void heapSort(long int *numbers, long int array_size)
{
    // Формируем нижний ряд пирамиды
    for (long int i = (array_size / 2) - 1; i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    // Просеиваем через пирамиду остальные элементы
    for (long int i = array_size - 1; i >= 1; i--)
    {
        long int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}


