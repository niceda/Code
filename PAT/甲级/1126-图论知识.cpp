#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int n, m, cnt = 0;
bool flag[501];
vector<vector<int>> v;
void count() {
  for (int i = 1; i <= n; i++) {
    if (flag[i] == false) {
      cnt++;
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int t = q.front();
        q.pop();
        flag[t] = true;
        for (int j = 0; j < v[t].size(); j++) {
          if (flag[v[t][j]] == false) {
            q.push(v[t][j]);
          }
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;
  v.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int oddcnt = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i].size() % 2 != 0) {
      oddcnt++;
    }
    if (i != 1)
      cout << " ";
    cout << v[i].size();
  }
  cout << endl;
  count();
  if (cnt == 1) {
    if (oddcnt == 0) {
      cout << "Eulerian";
    } else if (oddcnt == 2) {
      cout << "Semi-Eulerian";
    } else {
      cout << "Non-Eulerian";
    }
  } else {
    cout << "Non-Eulerian";
  }
  return 0;
}
