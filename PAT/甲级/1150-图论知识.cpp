#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

const int inf = 999999999;
int e[201][201];

int main() {
  int n, m, k;
  cin >> n >> m;
  fill(e[0], e[0] + 201 * 201, inf);
  for (int i = 0; i < m; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    e[a][b] = e[b][a] = d;
  }
  cin >> k;
  int min = inf, index;
  for (int i = 1; i <= k; i++) {
    int isTsCycle = 1, isSimpleCycle = 1, cnt, start, totalDist = 0, isNA = 0,
        last;
    vector<int> isvisit(n + 1);
    cin >> cnt >> start;
    isvisit[start]++;
    last = start;
    for (int j = 1; j < cnt; j++) {
      int a;
      cin >> a;
      if (j == cnt - 1 && a != start) {
        isTsCycle = 0;
      }
      if (e[last][a] != inf) {
        totalDist += e[last][a];
      } else if (e[last][a] == inf) {
        isNA = 1;
        isTsCycle = 0;
      }
      if ((isvisit[a] >= 1 && a != start) ||
          (isvisit[a] >= 1 && a == start && j != cnt - 1)) {
        isSimpleCycle = 0;
      }
      isvisit[a]++;
      last = a;
    }
    for (int i = 1; i <= n; i++) {
      if (isvisit[i] == 0) {
        isTsCycle = 0;
      }
    }
    if (isTsCycle == 1) {
      if (isSimpleCycle == 1) {
        printf("Path %d: %d (TS simple cycle)\n", i, totalDist);
      } else if (isSimpleCycle == 0) {
        printf("Path %d: %d (TS cycle)\n", i, totalDist);
      }
      if (totalDist < min) {
        min = totalDist;
        index = i;
      }
    } else if (isTsCycle == 0) {
      if (isNA == 1) {
        printf("Path %d: NA (Not a TS cycle)\n", i);
      } else if (isNA == 0) {
        printf("Path %d: %d (Not a TS cycle)\n", i, totalDist);
      }
    }
  }
  printf("Shortest Dist(%d) = %d", index, min);
  return 0;
}
