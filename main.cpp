#include "src/b_s.h"
#include "src/i_b_s.h"
#include <iostream>
using namespace std;

//функция проверки массива на упорядоченность
bool Check_Ideal_Array(int **array, int N) {
  int vector[N * N];
  int count = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      vector[count] = array[i][j];
      count = count + 1;
    }
    count = count + 1;
  }
  for (int i = 0; i < (N * N - 1); i++) {
    if (vector[i] > vector[i + 1]) {
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
  int **array = new int *[N];
  int m = 1;
  for (int i = 0; i < N; i++) {
    array[i] = new int[N];
    for (int j = 0; j < N; j++) {
      array[i][j] = m;
      m = m + 1;
      cout << array[i][j] << " | ";
    }
    cout << endl;
  }
/*  if (Check_Ideal_Array(array, N) == false) {
    cout << "Массив не упорядочен!" << endl;
    return -1;
  }*/
  cout << "Введите ключ: " << endl;
  cin >> key;
  int vector[N];
  for (int i = 1; i < N; i++) {
    cout << "\nВектор выше главной диагонали номер " << i<<":";
    for (int j = 0; j < (N  - i); j++) {
      vector[j]=array[j][j+i];
      cout<<" "<<vector[j];
    }
    index=Search_Binary(vector,N-i,key);
    if (index<0){ cout<<" Элемента нет в данном векторе";} else
    {cout<<"  Индекс="<<index<<","<<index+i;}
  }
  return 0;
}
