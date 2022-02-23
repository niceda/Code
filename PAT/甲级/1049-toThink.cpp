#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int f(int n) {
  if (n < 1) return 0;
  if (n < 10) return 1;
  int cnt = 1, basenum = 0, totalnum;
  while (pow(10, cnt) <= n) cnt++;
  for (int i = 1; i < cnt; i++) {
    basenum = 10 * basenum + pow(10, i - 1);
  }
  totalnum = basenum;
  int t = n - pow(10, cnt - 1);
  if (t < pow(10, cnt - 1)) {
    totalnum += t + 1;
    totalnum += f(t);
    return totalnum;
  } else {
    totalnum += pow(10, cnt - 1) + basenum;
    t -= pow(10, cnt - 1);
  }
  while (t >= pow(10, cnt - 1)) {
    t -= pow(10, cnt - 1);
    totalnum += basenum;
  }
  totalnum += f(t);
  return totalnum;
}

int main() {
  int n;
  scanf("%d", &n);
  cout << f(n);
  return 0;
}
