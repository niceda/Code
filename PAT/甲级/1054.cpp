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
  int n, m, t;
  cin >> n >> m;
  map<int, int> mapp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> t;
      mapp[t]++;
    }
  }
  int max = -1, result;
  for (auto val : mapp) {
    if (val.second > max) {
      result = val.first;
      max = val.second;
    }
  }
  cout << result;
  return 0;
}
