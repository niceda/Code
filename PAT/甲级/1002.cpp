#include <iostream>
using namespace std;

int main() {
  int k, n;
  double v[1001] = {0}, a;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> n >> a;
    v[n] += a;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> n >> a;
    v[n] += a;
  }
  k = 0;
  for (int i = 0; i < 1001; i++) {
    if (v[i] != 0)
      k++;
  }
  cout << k;
  for (int i = 1000; i >= 0; i--) {
    if (v[i] != 0)
      printf(" %d %.1lf", i, v[i]);
  }
  return 0;
}
