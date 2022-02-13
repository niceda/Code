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
  string s1, s2;
  int c[129] = {0};
  getline(cin, s1);
  getline(cin, s2);
  for (int i = 0; i < s2.length(); i++) {
    c[s2[i]] = 1;
  }
  for (int i = 0; i < s1.length(); i++) {
    if (c[s1[i]] == 0) {
      cout << s1[i];
    }
  }
  return 0;
}
