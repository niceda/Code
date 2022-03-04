#include <iostream>
using namespace std;

int v[1001][1001];
bool vis[1010];
int n;

void dfs(int node) {
  vis[node] = true;
  for (int i = 1; i <= n; i++) {
    if (v[node][i] == 1 && vis[i] == false) {
      dfs(i);
    }
  }
}


int main() {
  int m, k;
  cin >> n >> m >> k;
  int a, b, node;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    v[a][b] = v[b][a] = 1;
  }
  for (int i = 0; i < k; i++) {
    fill(vis, vis + 1001, false);
    cin >> node;
    vis[node] = true;
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (vis[j] == false) {
        dfs(j);
        cnt++;
      }
    }
    printf("%d\n", cnt - 1);
  }
  return 0;
}
