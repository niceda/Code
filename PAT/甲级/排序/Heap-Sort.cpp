#include <iostream>
#include <cmath>
using namespace std;
void adjustHeap(int *v, int node, int len) {
  int index = node;
  int child = 2 * index + 1;
  while( child < len) {
    if (child + 1 < len && v[child] < v[child+1]) {
      child++;
    }
    if (v[index] >= v[child]) break;
    swap(v[index], v[child]);
    index = child;
    child = 2 * index + 1;
  }
}
void makeHeap(int *v, int len) {
  for (int i = len / 2 - 1; i >= 0; i--) {
    adjustHeap(v, i, len);
  }
}
void heapSort(int *v, int len) {
  makeHeap(v, len);
  for (int i = len - 1; i >= 0; i--) {
    swap(v[i], v[0]);
    adjustHeap(v, 0, i);
  }
}

int main() {
  int v[10] = {4, 2, 1, 3, 4352, 345, 2342345, 5, 6, 7};
  heapSort(v, 10);
  for (int i = 0; i < 10; i++) {
    cout << v[i] << " ";
  }
}
