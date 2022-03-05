#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int v[5];

int main() {
  int n, k, t;
  scanf("%d %d", &n, &k);
  if (k > n)
   k = n;
  priority_queue<int, vector<int>, greater<int>> qp;
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    if (i < k)
      qp.push(t);
    else if (qp.top() < t) {
      qp.pop();
      qp.push(t);
    }
  }
  for (int i = 0; i < k; i++) {
    int t = qp.top();
    v[i] = t;
    qp.pop();
    // if (i != 0) printf(" ");
    // printf("%d", t);
  }
  for (int i = k - 1; i >= 0; i--) {
    if (i != k - 1) printf(" ");
    cout << v[i];
  }
  return 0;
}