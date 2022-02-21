#include <iostream>
#include <vector>
using namespace std;
const int inf = 999999999;
int e[510][510], weight[510], d[510];
bool vis[510];
vector<int> pre[510], path, temppath;
int n, m, st = 0, ed;

void DFS(int v) {
  temppath.push_back(v);
  if (st == ed) {
    // 遍历temppath
    temppath.pop_back();
    return;
  }
  for (int i = 0; i < pre[v].size(); i++) {
    DFS(pre[v][i]);
  }
  temppath.pop_back();
}

int main() {
  fill(e[0], e[0] + 510 * 510, inf);
  int u, v, dis;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &dis);
    e[u][v] = e[v][u] = dis;
  }

  fill(d, d + 510, inf);
  d[st] = 0;
  for (int i = 0; i <= n; i++) {
    int u = -1, minn = inf;
    for (int j = 0; j <= n; j++) {
      if (vis[j] == false && d[j] < minn) {
        u = j;
        minn = d[j];
      }
    }
    if (u == -1) break;
    vis[u] = true;
    for (int v = 0; v <= n; v++) {
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

  DFS(ed);
  return 0;
}
