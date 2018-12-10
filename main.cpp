#include "src/b_s.h"
#include "src/i_b_s.h"
#include <iostream>
using namespace std;

//функция проверки массива на упорядоченность
bool Check_Ideal_Array(int array[], int N) {
  for (int i = 0; i < (N * N - 1); i++) {
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
  cout << "Введите размерность массива" << endl;
  cin >> N;
  // заполняем и показываем массив размерности N*N
  int array[N * N];
  int m = 1;
  for (int j = 0; j < N * N; j++) {
    /*array[j] = m;
    cout << array[j] << " | ";
    if (m % N == 0) {
      cout<<endl;}
    m = m + 1;*/
    cin >> array[j];
  }
  for (int j = 0; j < N * N; j++) {
    cout << array[j] << " | ";
    if ((j+1) % N == 0) {
      cout << endl;
    }
  }
  cout << endl;
  //Проверка массива на упорядоченность
//  if (Check_Ideal_Array(array, N) == false) {
//    cout << "Массив не упорядочен!" << endl;
//    return -1;
//  }

  cout << "Введите ключ: " << endl;
  cin >> key;

  int vector[N - 1]; //вектор параллельный главной диагонали
  //Поиск по ключу в векторах,которые диагонали паралелльные главной
  for (int i = 1; i < N; i++) {
    cout << "\nВектор выше главной диагонали номер " << i << ":";
    for (int j = 0; j < (N - i); j++) {
      vector[j] = array[j * (N + 1) + i];
      cout << " " << vector[j];
    }
    index = Int_Search_Binary(vector, N - i, key);
    if (index < 0) {
      cout << " Элемента нет в данном векторе";
    } else {
      cout << "  Индекс=" << index << "," << index + i;
    }
    cout << "\nВектор ниже главной диагонали номер " << i << ":";
    for (int j = 0; j < (N - i); j++) {
      vector[j] = array[j * (N + 1) + i * N];
      cout << " " << vector[j];
    }
    index = Int_Search_Binary(vector, N - i, key);
    if (index < 0) {
      cout << " Элемента нет в данном векторе";
    } else {
      cout << "  Индекс=" << index + i << "," << index;
    }
  }
  return 0;
}
