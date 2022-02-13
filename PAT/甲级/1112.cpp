#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int in[127];
int nostuck[127];

int main() {
  int k;
  string s;
  cin >> k >> s;
  char lastkey = '!';
  int cnt = 1;
  set<char> ss;
  vector<char> v;
  for (int i = 0; i < s.length(); i++) {
    if (lastkey == s[i]) {
      cnt++;
      if (cnt == k) {
        if (in[lastkey] == false) {
          v.push_back(lastkey);
          in[lastkey] = true;
        }
        lastkey = '!';
        cnt = 1;
      }
    } else {
      if (lastkey != '!') {
        ss.insert(lastkey);
      }
      lastkey = s[i];
      cnt = 1;
    }
  }
  for (auto val : ss) {
    nostuck[val] = true;
  }
  for (int i = 0; i < v.size(); i++) {
    if (!nostuck[v[i]]) {
      cout << v[i];
    }
  }
  cout << endl;
  for (int i = 0; i < s.length(); i++) {
    if (!nostuck[s[i]]) {
      cout << s[i];
      i += k - 1;
    } else {
      cout << s[i];
    }
  }
  return 0;
}
