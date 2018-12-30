#include "src/b_s.h"
#include "src/i_b_s.h"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

//функция проверки массива на упорядоченность
bool Check_Ideal_Array(int array[], int N) {
  for (int i = 0; i < (N - 1); i++) {
    if (array[i] > array[i + 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  int N = 0; //размерность массива
  int key = 0;
  int index = 0; // позиция ключа в массиве
  ifstream file; //переменная для файла

  file.open("example.txt");
  file >> N;
  if (N < 2) {
    cout << "Слишком маленький массивчик";
    return -1;
  }

  // заполняем и показываем массив размерности N*N
  int array[N * N];
  for (int j = 0; j < N * N; j++) {
    file >> array[j];
  }

  //Выводим введенный массив, но покрасивше
  for (int j = 0; j < N * N; j++) {
    cout << setw(4) << array[j] << " | ";
    if ((j + 1) % N == 0) {
      cout << endl;
    }
  }

  file >> key;
  cout << "key=" << key << endl;
  int vector[N]; //вектор параллельный главной диагонали

  //Поиск по ключу в векторах,которые диагонали паралелльные главной
  cout << "Бинарный поиск";
  for (int i = 0; i < N; i++) {
    cout << "\nВектор выше главной №" << i << ":";
    for (int j = 0; j < (N - i); j++) {
      vector[j] = array[j * (N + 1) + i];
      cout << " " << vector[j];
    }
    if (Check_Ideal_Array(vector, N - i) == true) {
      index = Search_Binary(vector, N - i, key);
      if (index < 0) {
        cout << " Элемента нет в данном векторе";
      } else {
        cout << "  Индекс=" << index << "," << index + i;
      }
    } else {
      cout << "Вектор не упорядочен!";
    }

    cout << "\nВектор ниже главной №" << i << ":";
    for (int j = 0; j < (N - i); j++) {
      vector[j] = array[j * (N + 1) + i * N];
      cout << " " << vector[j];
    }
    if (Check_Ideal_Array(vector, N - i) == true) {
      index = Search_Binary(vector, N - i, key);
      if (index < 0) {
        cout << " Элемента нет в данном векторе";
      } else {
        cout << "  Индекс=" << index + i << "," << index;
      }
    } else
      cout << "Вектор не упорядочен!";
  }

  cout << "\nИнтерполяционный бинарный поиск";
  for (int i = 0; i < N; i++) {
    cout << "\nВектор выше главной №" << i << ":";
    for (int j = 0; j < (N - i); j++) {
      vector[j] = array[j * (N + 1) + i];
      cout << " " << vector[j];
    }
    if (Check_Ideal_Array(vector, N - i) == true) {
      index = Int_Search_Binary(vector, N - i, key);
      if (index < 0) {
        cout << " Элемента нет в данном векторе";
      } else {
        cout << "  Индекс=" << index << "," << index + i;
      }
    } else {
      cout << "Вектор не упорядочен!";
    }

    cout << "\nВектор ниже главной №" << i << ":";
    for (int j = 0; j < (N - i); j++) {
      vector[j] = array[j * (N + 1) + i * N];
      cout << " " << vector[j];
    }
    if (Check_Ideal_Array(vector, N - i) == true) {
      index = Int_Search_Binary(vector, N - i, key);
      if (index < 0) {
        cout << " Элемента нет в данном векторе";
      } else {
        cout << "  Индекс=" << index + i << "," << index;
      }
    } else
      cout << "Вектор не упорядочен!";
  }
  file.close();
  return 0;
}
