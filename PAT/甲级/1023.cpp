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
  string s, ds;
  cin >> s;
  int r = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    int t = (s[i] - '0') * 2 + r;
    ds += t % 10 + '0';
    r = t / 10;
  }
  if ( r != 0) {
    ds += r + '0';
  }
  string copy = ds;
  reverse(ds.begin(), ds.end());
  sort(s.begin(), s.end());
  sort(copy.begin(), copy.end());
  if (s.length() != copy.length()) {
    cout << "No" << endl;
    cout << ds;
    return 0;
  } else {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != copy[i]) {
        cout << "No" << endl;
        cout << ds;
        return 0;
      }
    }
    cout << "Yes" << endl;
    cout << ds;
  }
  return 0;
}
