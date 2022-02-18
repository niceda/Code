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
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (int i = 1; i < n; i++) {
    if (v[i] > 0) {
      if (v[i-1] > 0) {
        if (v[i] - v[i-1] != 1 && v[i] != v[i-1]) {
          cout << v[i-1] + 1;
          return 0;
        }
      } else if (v[i-1] <= 0 && v[i] != 1) {
          cout << 1;
        return 0;
      }
    }
  }
  if (v.back() <= 0) {
    cout << 1;
  } else {
    cout << v.back() + 1;
  }
  return 0;
}
