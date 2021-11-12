#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int INF = 1000000000;
struct node {
  int v, dis;
};
vector<node> e[510];
int n, m, st, ed, weight[510];
int d[510], num[510], w[510];
set<int> pre[510];

int main() {
  scanf("%d%d%d%d", &n, &m, &st, &ed);
  for (int i = 0; i < n; i++) {
    scanf("%d", &weight[i]);
  }
  int a, b, c;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    e[a].push_back(node{b, c});
    e[b].push_back(node{a, c});
  }

  fill(d, d + 510, INF);
  d[st] = 0;
  w[st] = weight[st];
  num[st] = 1;

  for (int i = 0; i < n - 1; i++) {
    for (int u = 0; u < n; u++) {
      for (int j = 0; j < e[u].size(); j++) {
        int v = e[u][j].v;
        int dis = e[u][j].dis;
        if (dis + d[u] < d[j]) {
          d[v] = dis + d[u];
          w[v] = weight[u] + w[u];
          num[v] = num[u];
          pre[v].clear();
          pre[v].insert(u);
        } else if (dis + d[u] == d[j]) {
          if (w[v] < weight[u] + w[u]) {
            w[v] = weight[u] + w[u];
          }
          pre[v].insert(u);
          num[v] = 0;
          for (auto it = pre[v].begin(); it != pre[v].end(); it++) {
            num[v] += num[*it];
          }
        }
      }
    }
  }

  printf("%d %d", num[ed], w[ed]);
  return 0;
}
