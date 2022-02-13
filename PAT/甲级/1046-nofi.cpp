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
  int n, m, sum = 0;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
    }
    int result = 0;
    if (b - a < n / 2) {
      while (a++ != b) {
        result += v[a];
      }
    } else {
      while (a-- != b) {
        if (a == 0) {
          a = n;
        }
        result += v[a];
      }
    }
    if (sum - result < result) {
      result = sum - result;
    }
    cout << result << endl;
  }
  return 0;
}
