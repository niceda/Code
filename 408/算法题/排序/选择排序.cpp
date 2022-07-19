#include <iostream>
using namespace std;

void selectSort(int *v, int len) {
  for (int i = 0; i < len; i++) {
    int minindex = i;
    for (int j = i + 1; j < len; j++) {
      if (v[j] < v[minindex]) {
        minindex = j;
      }
    }
    swap(v[i], v[minindex]);
  }
}