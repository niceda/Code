#include <iostream>
using namespace std;

void shellSort(int *v, int len) {
  for (int div = len / 2; div >= 1; div /= 2) {
    for (int k = 0; k < div; k++) {
      for (int i = k + div; i < len; i += div) {
        for (int j = i; j >= k + div; j -= div) {
          if (v[j] < v[j-div]) {
            swap(v[j], v[j-div]);
          } else {
            break;
          }
        }
      }
    }
  }
}