#include <iostream>
#include "src/b_s.h"
using namespace std;

//функция проверки массива на упорядоченность
bool Check_Ideal_Array(int array[], int N) {
  for (int i = 0; i < N; i++) {
    if (array[i] > array[i + 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  const int N = 10;
  int array[N] = {};
  int key = 0;
  int index = 0; // позиция ключа в массиве
   // заполняем и показываем массив
  for (int i = 0; i < N; i++)
  {
    array[i] = i + 1;
    cout << array[i] << " | ";
    //cin>>array[i];
  }
  if (Check_Ideal_Array(array, N) == false) {
    cout << "Массив не упорядочен!" << endl;
    return -1;
  }
  cout << "\n\nВведите ключ: ";
  cin >> key;
  index = Search_Binary(array, N, key);
  if (index >= 0)
    cout << "Указанное число находится в ячейке с индексом: " << index
         << "\n\n";
  else
    cout << "В массиве нет такого числа!\n\n";

  return 0;
}
