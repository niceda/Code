#include <cmath>
#include <iostream>
using namespace std;

void quickSort1(int *a, int begin, int end) {
  if (begin < end) {
    int left = begin, right = end, pivot = a[begin];
    while (left < right) {
      while (a[right] >= pivot && left < right) right--;
      a[left] = a[right];
      while (a[left] <= pivot && left < right) left++;
      a[right] = a[left];
    }
    int pivotpos = left;
    a[left] = pivot;
    quickSort1(a, begin, pivotpos - 1);
    quickSort1(a, pivotpos + 1, end);
  }
}

void quickSort2(int *a, int begin, int end) {
  if (begin >= end) return;
  int left = begin, right = end, pivot = a[begin];
  while (left < right) {
    while (a[right] >= pivot && left < right) right--;
    while (a[left] <= pivot && left < right) left++;
    if (left < right) {
      swap(a[left], a[right]);
    }
  }
  int pivotpos = left;
  swap(a[pivotpos], a[begin]);
  quickSort2(a, begin, pivotpos - 1);
  quickSort2(a, pivotpos + 1, end);
}

void quickSort3(int *a, int begin, int end) {
  if (begin >= end) return;
  int prev = begin, cur = begin + 1, pivot = a[begin];
  while(cur <= end) {
    if (a[cur] < pivot && ++prev != cur) {
      swap(a[prev], a[cur]);
    }
    cur++;
  }
  int pivotpos = prev;
  swap(a[begin], a[pivotpos]);

  quickSort3(a, begin, pivotpos - 1);
  quickSort3(a, pivotpos + 1, end);
}

int main() {
  int arr[4] = {2, 3, 1, 4};
  quickSort3(arr, 0, 3);
  for (int i = 0; i < 4; i++) {
    cout << arr[i] << " ";
  }
}
