#include <iostream>
using namespace std;

 void insertSort(int *v, int len) {
  for (int i = 0; i < len; i++) {
    for (int j = i; j > 0; j--) {
      if (v[j] < v[j-1]) {
        swap(v[j], v[j-1]);
      } else {
        break;
      }
   }
  }
}