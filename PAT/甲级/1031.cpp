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
  string s;
  cin >> s;
  int k, n2;
  for (int i = 0; i < s.length() - 1; i++) {
    k = (s.length() + 2- i) / 2;
    if (2 *k + i - 2 == s.length() && i >= k) {
      n2 = i;
      break;
    }
  }
  for (int i = 0; i < k - 1; i++) {
    cout << s[i];
    for (int j = 0; j < n2 - 2; j++) {
      cout << " ";
    }
    cout << s[s.length() - i - 1] << endl;
  }
  for (int i = k - 1; i < s.length() - k + 1; i++) {
    cout << s[i];
  }
  return 0;
}
