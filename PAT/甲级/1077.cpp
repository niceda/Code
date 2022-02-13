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
  string s, result;
  getchar();
  getline(cin, s);
  result = s;
  n--;
  while(n-- != 0 && result.length() != 0) {
    getline(cin, s);
    int index;
    for (int i = s.length() - 1, j = result.length() - 1; i >= 0 && j >= 0; i--, j--) {
      if (s[i] != result[j]) {
        index = i + 1;
        break;
      }
      index = i;
    }
    result = s.substr(index);
  }
  if (result.empty()) {
    cout << "nai";
  } else {
    cout << result;
  }
  return 0;
}
