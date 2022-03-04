#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
map<int, int> pos;
vector<int> in, pre;

void lca(int inLeft, int inRight, int preRoot, int a, int b) {
  if (inLeft > inRight) return;
  int rootIn = pos[pre[preRoot]], aIn = pos[a], bIn= pos[b];
  if (aIn < rootIn && bIn < rootIn) {
    lca(inLeft, rootIn - 1, preRoot + 1, a, b);
  } else if (aIn > rootIn && bIn > rootIn) {
    lca(rootIn + 1, inRight, preRoot + (rootIn - inLeft) + 1, a, b);
  } else if ((aIn < rootIn && bIn > rootIn) || (aIn > rootIn && bIn < rootIn)) {
    printf("LCA of %d and %d is %d.\n", a, b, in[rootIn]);
  } else if (aIn == rootIn) {
    printf("%d is an ancestor of %d.\n", a, b);
  } else if (bIn == rootIn) {
    printf("%d is an ancestor of %d.\n", b, a);
  }
}

int main() {
  int m, n, a, b; 
  scanf("%d %d", &m, &n);
  in.resize(n + 1), pre.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &in[i]);
    pos[in[i]] = i;
  }
  for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    if (pos[a] == 0 && pos[b] == 0) {
      printf("ERROR: %d and %d are not found.\n", a, b);
    } else if (pos[a] == 0 || pos[b] == 0) {
      printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
    } else {
      lca(1, n, 1, a, b);
    }
  }
  return 0;
}
