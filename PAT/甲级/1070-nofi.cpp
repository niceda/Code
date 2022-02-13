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
  int num;
  float totalprice, unitprice;
};

bool cmp(node a, node b) { return a.unitprice > b.unitprice; }

int main() {
  int n, d;
  cin >> n >> d;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].num;
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i].totalprice;
    v[i].unitprice = v[i].totalprice / v[i].num;
  }
  sort(v.begin(), v.end(), cmp);
  float total = 0;
  for (int i = 0; i < n && d != 0; i++) {
    if (d >= v[i].num) {
      total += v[i].totalprice;
      d -= v[i].num;
    } else {
      total += ((float)d / v[i].num) * v[i].totalprice;
      d = 0;
    }
  }
  printf("%.2f", total);
  return 0;
}
