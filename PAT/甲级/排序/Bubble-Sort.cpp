#include <iostream>
#include <cmath>
using namespace std;

void bubbleSort(int *v, int len) {
  if (v == NULL) return;
  if (len <= 1) return;

  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - 1 - i; j++) {
      if (v[j] > v[j+1]) {
        swap(v[j], v[j+1]);
      }
    }
  }
  return;
}
