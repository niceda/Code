//　希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；随着增量逐渐减少，每组包含的关键词越来越多，当增量减至1时，整个文件恰被分成一组，算法便终止。
#include <iostream>
#include <cmath>
using namespace std;

void shellSort(int *v, int len) {
  if (v == NULL) return;
  if (len <= 1) return;

  for (int div = len / 2; div >= 1; div /= 2) {
    for (int k = 0; k < div; k++) {
      for (int i = k + div; i < len; i += div) {
        for (int j = i; j >= k + div; j -= div) {
          if (v[j] < v[j - div]) {
            swap(v[j], v[j-div]);
          } else {
            break;
          }
        }
      }
    }
  }
}
