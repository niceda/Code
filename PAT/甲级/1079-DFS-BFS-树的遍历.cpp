#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int n; 
double p, r, total = 0.0;
vector<int> v[100000];
int amount[100000];

void DFS(int index, double unitprice) {
  if (v[index].empty()) {
    total += amount[index] * unitprice;
    return;
  }

  for (int i = 0; i < v[index].size(); i++) {
    DFS(v[index][i], (1 + r / 100) * unitprice);
  }
}


int main() {
  cin >> n >> p >> r;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if (k == 0) {
      cin >> amount[i];
      continue;
    }
    for (int j = 0; j < k; j++) {
      int t;
      cin >> t;
      v[i].push_back(t);
    }
  }
  DFS(0, p);
  printf("%.1f", total);
  return 0;
}
