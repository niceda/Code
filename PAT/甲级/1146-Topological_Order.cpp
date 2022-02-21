#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int n, m, k, flag = 1, inDegree[1010];
vector<int> e[1010];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    e[u].push_back(v);
    inDegree[v]++;
  }
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    int judge = 1, v;
    vector<int> tin(inDegree, inDegree + n + 1);
    for (int j = 0; j < n; j++) {
      scanf("%d", &v);
      if (tin[v] != 0) judge = 0;
      for (int it : e[v]) tin[it]--;
    }
    if (judge == 1) continue;
    printf("%s%d", flag == 1 ? "" : " ", i);
    flag = 0;
  }
  return 0;
}
