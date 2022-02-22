#include <cstdio>
#include <set>
#include <vector>
using namespace std;
const int INF = 1000000000;
struct node {
  int v, dis;
};
vector<node> Adj[510];
int n, m, st, ed, weight[510];
int d[510], w[510], num[510];
set<int> pre[510];

void Bellman(int s) {
  fill(d, d + 510, INF);
  d[s] = 0;
  w[s] = weight[s];
  num[s] = 1;
  for (int i = 0; i < n - 1; i++) {
    for (int u = 0; u < n; u++) {
      for (int j = 0; j < Adj[u].size(); j++) {
        int v = Adj[u][j].v;
        int dis = Adj[u][j].dis;
        if (d[u] + dis < d[v]) {
          d[v] = d[u] + dis;
          w[v] = w[u] + weight[v];
          num[v] = num[u];
          pre[v].clear();
          pre[v].insert(u);
        } else if (d[u] + dis == d[v]) {
          if (w[u] + weight[v] > w[u])
            w[v] = w[u] + weight[v];
          pre[v].insert(u);
          num[v] = 0;
          for (auto it = pre[v].begin(); it != pre[v].end(); it++) {
            num[v] += num[*it];
          }
        }
      }
    }
  }
}

int main() {
  scanf("%d%d%d%d", &n, &m, &st, &ed);
  for (int i = 0; i < n; i++) {
    scanf("%d", &weight[i]);
  }
  int u, v, wt;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &wt);
    Adj[u].push_back(node{v, wt});
    Adj[v].push_back(node{u, wt});
  }
  Bellman(st);
  printf("%d %d", num[ed], w[ed]);
  return 0;
}
