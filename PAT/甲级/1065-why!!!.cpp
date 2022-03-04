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
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a >= 0 && b >= 0) {
      if (a > c || b > c || a > c - b) {
        printf("Case #%d: true\n", i);
      } else {
        printf("Case #%d: false\n", i);
      }
    } else if (a <= 0 && b <= 0) {
      if (a <= c || b <= c || a <= c - b) {
        printf("Case #%d: false\n", i);
      } else {
        printf("Case #%d: true\n", i);
      }
    } else {
      if (a + b > c) {
        printf("Case #%d: true\n", i);
      } else {
        printf("Case #%d: false\n", i);
      }
    }
  }
  return 0;
}
