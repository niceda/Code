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
  int distance;
  float price;
};
int n;
vector<node> v;

bool cmp(node a, node b) { return a.distance < b.distance; }

float currentPrice = 9999999;
int findMinPriceStation1(int d1, int d2) {
  int k;
  for (int i = 0; i < n; i++) {
    if (v[i].distance > d1 && v[i].distance <= d2 &&
        v[i].price < currentPrice) {
      currentPrice = v[i].price;
      k = i;
    }
  }
  return k;
}
int findMinPriceStation2(int d1, int d2) {
  int k;
  for (int i = 0; i < n; i++) {
    if (v[i].distance > d1 && v[i].distance <= d2 &&
        v[i].price <= currentPrice) {
      currentPrice = v[i].price;
      k = i;
    }
  }
  return k;
}

int tank, d, unit, maxrun;
int currentDistance = 0, currentTank = 0, index;
float result = 0;
void find(int currentDistance) {
  if (findMinPriceStation1(currentDistance, currentDistance + maxrun) > result) {
    if (currentDistance + maxrun >= d) {
      result += (float)(d - currentTank * unit) / unit * currentPrice;
    } else {
    }
  } else {
  }
}

int main() {
  cin >> tank >> d >> unit >> n;
  maxrun = tank * unit;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].price >> v[i].distance;
  }
  sort(v.begin(), v.end(), cmp);
  index = findMinPriceStation1(-1, currentDistance);
  return 0;
}
