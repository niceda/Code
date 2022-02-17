#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

struct node {
  int row, column;
};

int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int n;
    cin >> n;
    vector<node> v;
    vector<int> flag(n+ 1);
    flag[0] = 1;
    for (int j = 1; j <= n; j++) {
      int t;
      cin >> t;
      if (flag[0] == 0) {
        continue;
      }
      if (flag[t] == 1) {
        flag[0] = 0;
        continue;
      }
      for (int jj = 0; jj < v.size(); jj++) {
        double e = (double)(t - v[jj].row) / (j - v[jj].column);
        if (e == 1 || e == -1) {
          flag[0] = 0;
        }
      }
      if (flag[0] == 1) {
        flag[t] = 1;
        v.push_back({t, j});
      }
    }
    if (flag[0] == 1) {
      cout << "YES" << endl;
    } else if (flag[0] == 0) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
