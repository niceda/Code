void quickSort(int *a, int begin, int end) {
  if (begin < end) {
    int left = begin, right = end, pivot = a[begin];
    while (left < right) {
      while(a[right] >= pivot && left < right) right--;
      a[left] = a[right];
      while(a[left] <= pivot && left < right) left++;
      a[right] = a[left];
    }
    int pivotpos = left;
    a[left] = pivot;

    quickSort(a, begin, pivotpos - 1);
    quickSort(a, pivotpos + 1, end);
  }
}