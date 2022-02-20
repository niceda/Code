#include <iostream>
#include <cmath>
using namespace std;

void insertSort(int *v, int len) {
  if (v == NULL) return;
  if (len <= 1) return;
  for (int i = 1; i < len; i++) {
    for (int j = i; j > 0; j--) {
      if (v[j] < v[j-1]) {
        swap(v[j], v[j-1]);
      } else {
        break;
      }
    }
  }
  return;
}
