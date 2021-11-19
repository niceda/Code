#include <algorithm>
#include <iostream>
using namespace std;
int n, m, st, ed;
int e[510][510], weight[510], d[510], w[510], num[510];
bool vis[510];
const int INF = 1000000000;

int main() {
  scanf("%d%d%d%d", &n, &m, &st, &ed);
  for (int i = 0; i < n; i++) {
    scanf("%d", &weight[i]);
  }
  fill(e[0], e[0] + 510 * 510, INF);
  int a, b, c;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    e[a][b] = e[b][a] = c;
  }

  fill(d, d + 510, INF);
  d[st] = 0;
  w[st] = weight[st];
  num[st] = 1;

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
          w[v] = w[u] + weight[v];
          num[v] = num[u];
        } else if (d[u] + e[u][v] == d[v]) {
          if (w[u] + weight[v] > w[v])
            w[v] = w[u] + weight[v];
          num[v] += num[u];
        }
      }
    }
  }

  printf("%d %d", num[ed], w[ed]);
}
