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
  int n;
  cin >> n;
  set<int> ss;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    int friendid = 0;
    for (int j = 0; j < s.length(); j++) {
      friendid += s[j] - '0';
    }
    ss.insert(friendid);
  }
  cout << ss.size() << endl;
  int flag = 0;
  for (auto val : ss) {
    if (flag != 0) cout << " ";
    cout << val;
    flag = 1;
  }
  return 0;
}
