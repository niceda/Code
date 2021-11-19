#include <iostream>
#include <algorithm>
using namespace std;
struct node {
  int u, v, cost;
}E[1010];
bool cmp(node a, node b) {
  return a.cost < b.cost;
}
int father[510];
int findfather(int x) {
  int a = x;
  while (x != father[x]) {
    x = father[x];
  }
  while (a != x) {
    int z = a;
    a = father[a];
    father[z] = x;
  }
  return x;
}
int Kruskal(int n, int m) {
  for (int i = 0; i < n; i++) {
    father[i] = i;
  }
  int ans = 0, num_Edge = 0;
  sort(E, E + m, cmp);
  for (int i = 0; i < m; i++) {
    int faU = findfather(E[i].u);
    int faV = findfather(E[i].v);
    if (faU != faV) {
      father[faU] = faV;
      num_Edge++;
      ans += E[i].cost;
      if (num_Edge == n - 1) break;
    }
  }
  if (num_Edge != n - 1) return -1;
  else return ans;
}  

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> E[i].u >> E[i].v >> E[i].cost;
  }
  int ans = Kruskal(n, m);
  cout << ans;
  return 0;
}
