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
  int v[3];
  for (int i = 0; i < 3; i++) {
    cin >> v[i];
  }
  string s = "#";
  for (int i = 0; i < 3; i++) {
    string temp;
    if (v[i] == 0) {
      temp += '0';
    }
    int save = v[i];
    while (v[i] != 0) {
      int t = v[i] % 13;
      if (t < 10) {
        temp += t + '0';
      } else {
        temp += t - 10 + 'A';
      }
      v[i] /= 13;
    }
    if (save < 13) {
      temp += '0';
    }
    reverse(temp.begin(), temp.end());
    s += temp;
  }
  cout << s;
  return 0;
}
