#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int n, num = 0;
double p, r, lowestprice = 999999999;
vector<vector<int> > v;

void DFS(int index, double price) {
  if (v[index].empty()) {
    if (price < lowestprice) {
      num = 1;
      lowestprice = price;
    } else if (price == lowestprice) {
      num++;
    }
    return;
  }

  for (int i = 0; i < v[index].size(); i++) {
    DFS(v[index][i], price * (1 + r / 100));
  }
}


int main() {
  cin >> n >> p >> r;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    int k, t;
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> t;
      v[i].push_back(t);
    }
  }
  DFS(0, p);
  printf("%.4f %d", lowestprice, num);
  return 0;
}
