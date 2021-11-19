#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int G[510][510];
int ans = 0,d[510];
bool vis[510] = {false};
int main() {
  int n, m;
  cin >> n;
  fill(G[0], G[0] + 510 * 510, INF);
  int u, v, w;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    G[u][v] = G[v][u] = w;
  }
  fill(d, d + 510, INF);
  d[0] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, minn = INF;
    for (int v = 0; v < n; v++) {
      if (vis[v] == false && d[v] < minn) {
        u = v;
        minn = d[v];
      }
    }
    if (u == -1) break;
    vis[u] = true;
    ans += d[u];
    for (int v = 0; v < n; v++) {
      if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v]) {
        d[v] = G[u][v];
      }
    }
  }
  return 0;
}
