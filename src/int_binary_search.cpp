//интерполяционный бинарный поиск
int Int_Search_Binary(int A[], int N, int key) {
  int mid, left = 0, right = N - 1;
  while (A[left] <= key && A[right] >= key) {
    mid = left + ((key - A[left]) * (right - left)) / (A[right] - A[left]);
    if (A[mid] < key)
      left = mid + 1;
    else if (A[mid] > key)
      right = mid - 1;
    else
      return mid;
  }
  if (A[left] == key)
    return left;
  else
    return -1;
}
