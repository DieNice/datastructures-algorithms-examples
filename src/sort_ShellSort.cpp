void ShellSort(int *A, int n) //сортировка Шелла
{
  int i, j, d, count;
  d = n;
  d = d / 2;
  while (d > 0) {
    for (i = 0; i < n - d; i++) {
      j = i;
      while (j >= 0 && A[j] > A[j + d]) {
        count = A[j];
        A[j] = A[j + d];
        A[j + d] = count;
        j--;
      }
    }
    d = d / 2;
  }
}
