#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int main() {
  long n, p;
  cin >> n >> p;
  vector<long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int max = 1;
  for (int i = 0; i + max < n; i++) {
    while (v[i] * p >= v[i + max] && i + max < n) {
      max++;
    }
  }
  cout << max;
  return 0;
}
