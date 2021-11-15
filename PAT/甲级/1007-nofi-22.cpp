#include <iostream>
using namespace std;

int main() {
  int k, maxst, maxed, maxsum = -1, tempst, temped, tempsum = 0, t, flag = 0, flag1 = 0, first;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> t;
    if (i == 0)
      first = t;
    tempsum += t;
    if (tempsum < 0) {
      tempsum = 0;
      flag = 0;
    } else if (tempsum >= 0) {
      if (flag == 0) {
        tempst = t;
        flag = 1;
      }
      temped = t;
      flag1 = 1;
    }
    if (tempsum > maxsum) {
      maxsum = tempsum;
      maxst = tempst;
      maxed = temped;
    }
  }

  if (flag1 == 0) {
    maxst = first;
    maxed = t;
    maxsum = 0;
  }
  cout << maxsum << " " << maxst << " " << maxed; 
  return 0;
}
