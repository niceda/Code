#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

set<int> v[1001];
bool flag[1001];

int main() {
  int n, l, queryN;
  cin >> n >> l;
  for (int i = 1; i <= n; i++) {
    int t, tt;
    cin >> t;
    for (int j = 0; j < t; j++) {
      cin >> tt;
      v[tt].insert(i);
    }
  }
  cin >> queryN;
  for (int i = 0; i < queryN; i++) {
    fill(flag, flag + 1001, false);
    int id;
    cin >> id;
    set<int> s = v[id];
    set<int> t = s;

    for (auto val1 : s) {
      flag[val1] = true;
      for (auto val2 : v[val1]) {
        if (val2 != id) {
          t.insert(val2);
        }
      }
    }

    s = t;

    for (auto val1 : s) {
      if (flag[val1] == false) {
        flag[val1] = true;
        for (auto val2 : v[val1]) {
          if (val2 != id) {
            t.insert(val2);
          }
        }
      }
    }

    cout << t.size() << endl;
  }

  return 0;
}
