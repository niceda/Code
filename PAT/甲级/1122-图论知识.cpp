#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int e[201][201];
const int inf = 999999999;

int main() {
  int n, m, k;
  cin >> n >> m;
  fill(e[0], e[0] + 201 * 201, inf);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    e[a][b] = e[b][a] = 1;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int kk, start, last;
    vector<int> flag(n + 1);
    cin >> kk;
    cin >> start;
    last = start;
    flag[start] = 1;
    flag[0] = 1;
    for (int j = 0; j < kk - 1; j++) {
      int t;
      cin >> t;
      if (e[last][t] == 1) {
        flag[t]++;
        last = t;
      } else {
        flag[0] = 0;
      }
    }
    if (flag[0] == 1) {
      if (flag[start] == 2 && last == start) {
        int flagg = 1;
        for (int j = 1; j <= n; j++) {
          if (j != start && flag[j] !=  1) {
            cout << "NO" << endl;
            flagg = 0;
            break;
          }
        }
        if (flagg == 1) {
          cout << "YES" << endl;
        }
      } else {
        cout << "NO" << endl;
      }
    } else if (flag[0] == 0) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
