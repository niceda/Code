#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int e[510][510], cost[510][510], d[510];
bool vis[510];
const int inf = 999999999;
int mincost = inf;
vector<int> pre[510];
vector<int> path, temppath;

void dfs(int index) {
  temppath.push_back(index);
  if (pre[index].empty()) {
    int t = 0;
    for (int i = temppath.size() - 2; i >= 0; i--) {
      t += cost[temppath[i + 1]][temppath[i]];
    }
    if (t < mincost) {
      mincost = t;
      path = temppath;
    }
    temppath.pop_back();
    return;
  }
  for (int i = 0; i < pre[index].size(); i++) {
    dfs(pre[index][i]);
  }
  temppath.pop_back();
}

int main() {
  int n, m, start, end;
  cin >> n >> m >> start >> end;
  fill(e[0], e[0] + 510 * 510, inf);
  int u, v, dist, costt;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> dist >> costt;
    e[u][v] = e[v][u] = dist;
    cost[u][v] = cost[v][u] = costt;
  }
  fill(d, d + 510, inf);
  d[start] = 0;

  for (int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for (int j = 0; j < n; j++) {
      if (vis[j] == false && d[j] < minn) {
        u = j;
        minn = d[j];
      }
    }

    if (u == -1) {
      break;
    }
    vis[u] = true;

    for (int v = 0; v < n; v++) {
      if (vis[v] == false && e[u][v] != inf) {
        if (d[u] + e[u][v] < d[v]) {
          d[v] = d[u] + e[u][v];
          pre[v].clear();
          pre[v].push_back(u);
        } else if (d[u] + e[u][v] == d[v]) {
          pre[v].push_back(u);
        }
      }
    }
  }

  dfs(end);
  for (int i = path.size() - 1; i >= 0; i--) {
    cout << path[i] << " ";
  }
  cout << d[end] << " " << mincost;

  return 0;
}
