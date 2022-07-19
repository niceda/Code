#include <iostream>
using namespace std;

void mergeArray(int *v, int left, int mid, int right, int *temp) {
  int i = left, j = mid + 1, k = 0;
  while(i <= mid && j <= right) {
    if (v[i] <= v[j]) {
      temp[k++] = v[i++];
    } else {
      temp[k++] = v[j++];
    }
  }
  while(i <= mid) {
    temp[k++] = v[i++];
  }
  while(j <= right) {
    temp[k++] = v[j++];
  }
  memcpy(&v[left], temp, k * sizeof(int));
}

void _mergesort(int *v, int left, int right, int *temp) {
  if (left < right) {
    int mid = (left + right) / 2;
    _mergesort(v, left, mid, temp);
    _mergesort(v,  mid + 1, right, temp);
    mergeArray(v, left, mid, right, temp);
  }
}

void mergeSort(int *v, int len) {
  int *temp = (int*)malloc(len * sizeof(int));
  _mergesort(v, 0, len - 1, temp);
}