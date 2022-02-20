#include <iostream>
#include <cmath>
using namespace std;

void selectSort(int *v, int len) {
  if (v == NULL) return;
  if (len <= 1) return;

  for (int i = 0; i < len - 1; i++) {
    int minindex = i;
    for (int j = i + 1; j < len; j++) {
      if (v[j] < v[minindex]) {
        minindex = j;
      }
    }
    swap(v[i], v[minindex]);
  }
  return;
}

