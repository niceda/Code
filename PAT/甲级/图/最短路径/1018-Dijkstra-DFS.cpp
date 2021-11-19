#include <iostream>
#include <vector>
using  namespace std;
const int INF = 1000000000;
int cmax, n, m, st = 0, sp, G[510][510], weight[510];
int d[510];
vector<int> pre[510];
bool vis[510] = {false};
vector<int> path, temppath;
int minneed = INF, maxback = INF;

void DFS(int v) {
  temppath.push_back(v);
  if (v == st) {
    int need = 0, back = 0;
    for (int i = temppath.size() - 1; i >= 0; i--) {
      int id = temppath[i];
      if (weight[id] > 0)
       back += weight[id];
      else {
        if (back > (0 - weight[id])) {
          back += weight[id];
        } else {
          need += (0 - weight[id] - back);
          back = 0;
        }
      }
    }
    if (need < minneed) {
      minneed = need;
      maxback = back;
      path = temppath;
    } else if (need == minneed && back < maxback) {
      maxback = back;
      path = temppath;
    }
    temppath.pop_back();
    return ;
  }
  for (int i = 0; i < pre[v].size(); i++) {
    DFS(pre[v][i]);
  }
  temppath.pop_back();
}

int main() {
  scanf("%d%d%d%d", &cmax, &n, &sp, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &weight[i]);
    weight[i] = weight[i] - cmax / 2;
  }
  fill(G[0], G[0] + 510 * 510, INF);
  int u, v, dis;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &dis);
    G[u][v] = G[v][u] = dis;
  }

  fill(d, d + 510, INF);
  d[st] = 0;
  for (int i = 0; i <= n; i++) {
    int u = -1, minn = INF;
    for (int j = 0; j <= n ; j++) {
      if (vis[j] == false && d[j] < minn) {
        u = j;
        minn = d[j];
      }
    }
    if (u == -1) break ;
    vis[u] = true;
    for (int v = 0; v <= n; v++) {
      if (vis[v] == false && G[u][v] != INF) {
        if (d[u] + G[u][v] < d[v]) {
          d[v] = d[u] + G[u][v];
          pre[v].clear();
          pre[v].push_back(u);
        } else if (d[u] + G[u][v]  == d[v]) {
            pre[v].push_back(u);
        }
      }
    }
  }

  DFS(sp);
  cout << minneed << " ";
  for (int i = path.size() - 1; i >= 0; i--) {
    cout << path[i];
    if (i != 0) cout << "->";
  }
  cout << " " << maxback;
  return 0;
}
