#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int max = -1;
  string s, t, result;  
  getline(cin, s);
  map<string, int> m;
  for (int i = 0; i < s.length(); i++) {
    if (isalnum(s[i])) {
      t += tolower(s[i]);
      if (i == s.length() -1) {
        m[t]++;
      }
    } else {
      if (!t.empty()) {
        m[t]++;
      }
      t.clear();
    }
  }
  for (auto it : m) {
    if (it.second > max) {
      max = it.second;
      result = it.first;
    }
  }
  cout << result << " " << max;
  return 0;
}
