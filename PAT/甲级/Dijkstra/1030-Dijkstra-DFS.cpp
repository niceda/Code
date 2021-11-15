#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m, st, sp;
int e[510][510], d[510], cost[510][510];
vector<int> pre[510];
bool vis[510] = {false};
const int INF = 1000000000;
vector<int> path, temppath;
int mincost = INF;

void DFS(int v) {
  temppath.push_back(v);
  if (v == sp) {
    int tempcost = 0;
    for (int i = temppath.size() - 1; i >= 1; i--) {
      int id = temppath[i], nextid = temppath[i - 1];
      tempcost += cost[nextid][id];
    }
    if (tempcost < mincost) {
      mincost = tempcost;
      path = temppath;
    }
    temppath.pop_back();
    return;
  }
  for (int i = 0; i < pre[v].size(); i++)
    DFS(pre[v][i]);
  temppath.pop_back();
}

int main() {
  scanf("%d%d%d%d", &n, &m, &st, &sp);
  fill(e[0], e[0] + 510 * 510, INF);
  for (int i = 0; i < m; i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    e[a][b] = e[b][a] = c;
    cost[a][b] = cost[b][a] = d;
  }

  fill(d, d + 510, INF);
  // pre[st].push_back(st);
  d[sp] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, minn = INF;
    for (int j = 0; j < n; j++) {
      if (vis[j] == false && d[j] < minn) {
        u = j;
        minn = d[j];
      }
    }
    if (u == -1)
      break;
    vis[u] = true;
    for (int v = 0; v < n; v++) {
      if (vis[v] == false && e[u][v] != INF) {
        if (d[u] + e[u][v] < d[v]) {
          d[v] = d[u] + e[u][v];
          pre[v].clear();
          pre[v].push_back(u);
        } else if (d[u] + e[u][v] == d[v])
          pre[v].push_back(u);
      }
    }
  }

  DFS(sp);
  for (int i = path.size() - 1; i >= 0; i--) {
    cout << path[i] << " ";
  }
  cout << d[sp] << " " << mincost;
  return 0;
}
