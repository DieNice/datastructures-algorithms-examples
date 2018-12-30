//интерполяционный бинарный поиск
int Int_Search_Binary(int A[], int N, int key) {
  int m, l = 0, r = N - 1;

  while (A[l] < key && A[r] > key) {
    m = l + ((key - A[l]) * (r - l)) / (A[r] - A[l]);
    if (A[m] < key)
      l = m + 1;
    else if (A[m] > key)
      r = m - 1;
    else
      return m;
  }
  if (A[l] == key)
    return l;
  if (A[r] == key)
    return r;
  return -1;
}
