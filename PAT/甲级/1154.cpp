#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int n, m, k;
  scanf("%d %d", &n, &m);
  vector<vector<int>> v(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  scanf("%d", &k);
  vector<int> color(n);
  for (int i = 0; i < k; i++) {
    set<int> s;
    for (int j = 0; j < n; j++) {
      cin >> color[j];
      s.insert(color[j]);
    }
    int flag = 1;
    for (int j = 0; j < n && flag == 1; j++) {
      for (int z = 0; z < v[j].size(); z++) {
        if (color[j] == color[v[j][z]]) {
          flag = 0;
          break;
        }
      }
    }
    if (flag == 1) {
      printf("%d-coloring\n", (int)s.size());
    } else {
      printf("No\n");
    }
  }
  return 0;
}
