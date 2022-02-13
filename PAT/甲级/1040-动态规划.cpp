#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

bool judge(string s) {
  string rev = s;
  // reverse(s.begin(), s.end());
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != rev[s.length() - 1 - i]) {
      return false;
    }
  }
  // return s == rev;
  return true;
}

int main() {
  string s;
  getline(cin, s);
  for (int i = s.length(); i >= 1; i--) {
    string substr;
    for (int j = 0; j < s.length() - i + 1; j++) {
      substr = s.substr(j, i);
      if (judge(substr)) {
        cout << i;
        return 0;
      }
    }
  }
  return 0;
}
