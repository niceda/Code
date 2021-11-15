#include <iostream>
using namespace std;
int G[1001][1001];
bool vis[1001];
int n; 

void DFS(int v) {
  vis[v] = true;
  for (int i = 1; i <= n; i++) {
    if (G[v][i] == 1 && vis[i] == false)
      DFS(i);
  }
}

int main() {
  int m, k;
  cin >> n >> m >> k;
  int a, b, v;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    G[a][b] = G[b][a] = 1;
  }
  for (int i = 0; i < k; i++) {
    fill(vis, vis + 1001, false);
    cin >> v;
    vis[v] = true;
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (vis[j] == false) {
        DFS(j);
        cnt++;
      }
    }
    printf("%d\n", cnt - 1);
  }
  return  0;
}
