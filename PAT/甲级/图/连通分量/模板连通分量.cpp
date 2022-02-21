#include <iostream>
using namespace std;
int e[510][510];
int vis[510];
int n;

void dfs(int v) {
  vis[v] = 1;
  for (int i = 1; i <= n; i++) {
    if (e[v][i] == 1 && vis[i] == 0) {
      dfs(i);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    e[a][b] = e[b][a] = 1;
  }
  fill(vis, vis + 510, 0);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      cnt++;
      dfs(i);
    }
  }
  cout << cnt;
}
