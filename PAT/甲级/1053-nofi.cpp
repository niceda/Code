#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int n, m, s;
vector<int> weight;
vector<vector<int>> v;
vector<int> temppath;
vector<vector<int>> path;

void dfs(int id) {
  temppath.push_back(id);
  if (v[id].empty()) {
    int t = 0;
    for (int i = 0; i < temppath.size(); i++) {
      t += weight[temppath[i]];
    }
    if (t == s) {
      path.push_back(temppath);
    }
    temppath.pop_back();
    return;
  }

  for (int i = 0; i < v[id].size(); i++) {
    dfs(v[id][i]);
  }
  temppath.pop_back();
}

bool cmp(vector<int> &a, vector<int> &b) {
  for (int i = 0; i < a.size() && i < b.size(); i++) {
    if (weight[a[i]] > weight[b[i]]) {
      return true;
    } else if (weight[a[i]] < weight[b[i]]) {
      return false;
    }
  }
  if (a.size() >= b.size()) {
    return true;
  } else {
    return false;
  }
}

int main() {
  cin >> n >> m >> s;
  weight.resize(n);
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }
  int id, count, t;
  for (int i = 0; i < m; i++) {
    cin >> id >> count;
    for (int j = 0; j < count; j++) {
      cin >> t;
      v[id].push_back(t);
    }
  }
  dfs(0);
  sort(path.begin(), path.end(), cmp);
  for (int i = 0; i < path.size(); i++) {
    for (int j = 0; j < path[i].size(); j++) {
      if (j != 0)
        cout << " ";
      cout << weight[path[i][j]];
    }
    cout << endl;
  }
  return 0;
}
