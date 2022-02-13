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
  int n, k;
  cin >> n >> k;
  map<string, set<int>> m;
  string name;
  for (int i = 0; i < k; i++) {
    int index, count;
    cin >> index >> count;
    for (int j = 0; j < count; j++) {
      cin >> name;
      m[name].insert(index);
    }
  }
  while (n-- != 0) {
    cin >> name;
    cout << name << " " << m[name].size();
    for (auto var : m[name]) {
      cout << " " << var;
    }
    cout << endl;
  }
  return 0;
}
