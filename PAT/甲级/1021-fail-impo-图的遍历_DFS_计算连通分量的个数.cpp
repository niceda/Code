#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
int n, maxheight = 0;
vector<vector<int>> v;
bool vis[10001] = {false};
set<int> temp;

void DFS(int node, int height) {
    if (height > maxheight) {
      maxheight = height;
      temp.clear();
      temp.insert(node);
    } else if (height == maxheight) {
      temp.insert(node);
    }
  vis[node] = true;
  // cout << node << "node-----------------------" << endl;
  for (int i = 0; i < v[node].size(); i++) {
    if (vis[v[node][i]] == false) {
      DFS(v[node][i], height + 1);
    }
  }
}

int main() {
  int n;
  cin >> n;
  v.resize(n + 1);
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == false) {
      DFS(i, 1);
      cnt++;
    }
  }
  // cout << cnt << "---------------------------" << endl;
  if (cnt >= 2) {
    printf("Error: %d components", cnt);
    return 0;
  } else {
    set<int> total = temp;
    fill(vis, vis + 10001, false);
    DFS(*temp.begin(), 1);
    for (auto var: temp) {
      total.insert(var);
    }
    for (auto var: total) {
      cout << var << endl;
    }
  }
  return 0;
}
