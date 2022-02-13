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
  int n, t, flag = 0;
  cin >> n;
  map<int, bool> m;
  vector<int> order;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (m.find(t) == m.end()) {
      m[t] = true;
      order.push_back(t);
    } else {
      m[t] = false;
    }
  }
  for (int i = 0; i < order.size(); i++) {
    if (m[order[i]] == true) {
      cout << order[i];
      return 0;
    }
  }
  cout << "None";
  return 0;
}
