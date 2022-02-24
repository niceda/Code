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
  int m, n, k;
  cin >> m >> n >> k;
  for (int i = 0; i < k; i++) {
    int popsum = 0, max = 1, flag = 1;
    vector<int> v(n+1);
    stack<int> s;
    for (int j = 1; j <= n; j++) {
      cin >> v[j];
    }
    for (int j = 1; j <= n; j++) {
      if (v[j] - popsum > m) {
        cout << "NO" << endl;
        flag = 0;
        break;
      }
      if (s.empty() || v[j] >= max) {
        for (int i = max; i < v[j]; i++) {
          s.push(i);
        }
        max = v[j] + 1;
      } else if (s.top() == v[j]) {
        s.pop();
      } else if (s.top() != v[j]) {
        cout << "NO" << endl;
        flag = 0;
        break;
      }
      popsum++;
    }
    if (flag == 1) {
      cout << "YES" << endl;
    }
  }
  return 0;
}
