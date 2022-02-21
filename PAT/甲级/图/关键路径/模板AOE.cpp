#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
struct node {
  int v, w;
};
int n;
vector<int> ve, vl, indegree;
vector<vector<node>> G;
stack<int> toporder;

bool topologicSort() {
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0)
      q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    toporder.push(u);
    q.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i].v;
      indegree[v]--;
      if (indegree[v] == 0)
        q.push(v);

      if (ve[u] + G[u][i].w > ve[v])
        ve[v] = ve[u] + G[u][i].w;
    }
  }
  if (toporder.size() != n)
    return false;
  return true;
}

int CriticalPath() {
  if (topologicSort() == false)
    return -1;
  int maxLength = 0;
  for (int i = 0; i < n; i++) {
    if (maxLength < ve[i])
      maxLength = ve[i];
  }
  fill(vl[0], vl[0] + n, maxLength);
  while (!toporder.empty()) {
    int u = toporder.top();
    toporder.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i].v;
      if (vl[u] - G[u][i].w < vl[v])
        vl[v] = vl[u] - G[u][i].w;
    }
  }
  for (int u = 0; u < n; u++) {
    int e = ve[u];
    for (int j = 0; j < G[u].size(); j++) {
      int v = G[u][j].v, l = vl[v] - G[u][j].w;
      if (e == l)
        printf("%d->%d\n", u, v);
    }
  }
  return maxLength;
}

int main() { return 0; }
