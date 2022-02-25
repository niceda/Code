#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

struct node {
  double num, totalprice;
};

bool cmp(node a, node b) { return a.totalprice * b.num > b.totalprice * a.num; }

int main() {
  int n, d;
  double total = 0.00;
  cin >> n >> d;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].num;
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i].totalprice;
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < n; i++) {
    if (d >= v[i].num) {
      total += v[i].totalprice;
      d -= v[i].num;
    } else {
      total += d * v[i].totalprice / v[i].num;
      break;
    }
  }
  printf("%.2f", total);
  return 0;
}
