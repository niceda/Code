#include <iostream>
#include <vector>
using namespace std;

int main() {
  int k;
  cin >> k;
  vector<int> v(k);
  for (int i = 0; i < k; i++) {
    cin >> v[i];
  }
  int st = 0, ed = 0, sum = 0, opst, oped, max = -1000000000;
  while (ed < k) {
    sum += v[ed];
    if (sum > max) {
      opst = st;
      oped = ed;
      max = sum;
    }
    if (sum < 0) {
      sum = 0;
      ed++;
      st = ed;
    } else {
      ed++;
    }
  }

  if (max < 0) {
    if (k > 0) {
      cout << 0 << " " << v[0] << " " << v[k - 1];
    } else {
      cout << 0 << " " << v[0] << " " << v[0];
    }
  } else {
    cout << max << " " << v[opst] << " " << v[oped];
  }
  return 0;
}
