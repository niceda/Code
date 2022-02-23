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
  int n, m, sum = 0, t;
  scanf("%d", &n);
  vector<int> v(n + 1);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &t);
    sum += t;
    v[i] = t + v[i - 1];
  }
  scanf("%d", &t);
  sum += t;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) {
      swap(a, b);
    }
    int t = v[b] - v[a];
    printf("%d\n", min(t, sum - t)); 
  }
}
