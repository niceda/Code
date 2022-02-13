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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<set<string>> v(m + 1);
  int c, t;
  string name;
  for (int i = 1; i <= n; i++) {
    cin >> name;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
      scanf("%d", &t);
      v[t].insert(name);
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << i << " " << v[i].size() << endl;
    for (auto val : v[i]) {
      cout << val << endl;
    }
  }
  return 0;
}
