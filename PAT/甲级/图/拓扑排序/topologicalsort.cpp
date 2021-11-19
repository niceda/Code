#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> G[510];  
int n, m, inDegree[510];

bool topologicalSort() {
  int num = 0;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (inDegree[n] == 0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    // cout << u << " ";
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      inDegree[v]--;
      if (inDegree[v] == 0)
        q.push(v);
    }
    // G[u].clear();
    num++;
  }
  if (num != n) return false;
  else return true;
}

int main() {
  int u, v;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    G[u].push_back(v);
    inDegree[u]++;
  }
  bool flag = topologicalSort();
  if (flag) cout << "G is Directed Acyclic Graph";
  else cout << "G exits Acyclic";
  return 0;
}
