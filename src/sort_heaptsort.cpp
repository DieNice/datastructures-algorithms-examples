#include <iostream>
using namespace std;

int swp = 0; //кол-во свапов
int eql = 0; //кол-во сравнений

// Функция "просеивания" через кучу - формирование кучи
void siftDown(int *numbers, int root, int bottom) {
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована

  // Пока не дошли до последнего ряда
  while ((root * 2 + 1 <= bottom) && (!done)) {
    if (root * 2 + 1 == bottom) { // если мы в последнем ряду,
      maxChild = root * 2 + 1;
      eql++;
    } // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2 + 1] > numbers[root * 2 + 2])
      maxChild = root * 2 + 1;
    else
      maxChild = root * 2 + 2;
    // если элемент вершины меньше максимального потомка
    eql = eql + 2;
    if (numbers[root] < numbers[maxChild]) {
      swp++;                    //тут
      int temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    } else      // иначе
      done = 1; // пирамида сформирована
  }
}

// Функция сортировки на куче
void heapSort(int *numbers, int array_size) {
  //строим сортирующее дерево
  for (int i = array_size / 2 - 1; i >= 0; i--)
    siftDown(numbers, i, array_size - 1);
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i > 0; i--) {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    swp++; //тут
    siftDown(numbers, 0, i - 1);
  }
  cout << "swap=" << swp << endl;
  cout << "eq=" << eql << endl;
}
