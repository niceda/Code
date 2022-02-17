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
  int n, m, k;
  cin >> n >> m;
  vector<vector<int>> v(n);
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(i);
    v[b].push_back(i);
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int kk;
    cin >> kk;
    vector<int> flag(m + 1);
    for (int j = 0; j < kk; j++) {
      int t;
      cin >> t;
      for (int jj = 0; jj < v[t].size(); jj++) {
        flag[v[t][jj]] = 1;
      }
    }
    int flagg = 1;
    for (int j = 1; j <= m; j++) {
      if (flag[j] == 0) {
        cout << "No" << endl;
        flagg = 0;
        break;
      }
    }
    if (flagg == 1) {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
