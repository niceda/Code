#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int a[], int left, int right, int x) {
  while (left <= right) {
    int mid = (left + right) / 2;
    if (a[mid] == x)
      return mid;
    if (a[mid] > x)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return -1;
}

int lower_bound(int a[], int left, int right, int x) {
  while (left < right) {
    int mid = (left + right) / 2;
    if (a[mid] >= x) // 返回第一个满足该条件的位置
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

int upper_bound(int a[], int left, int right, int x) {
  while (left < right) {
    int mid = (left + right) / 2;
    if (a[mid] > x) // 返回第一个满足该条件的位置
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

int main() { return 0; }
