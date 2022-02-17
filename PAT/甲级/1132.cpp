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
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int t = stoi(s);
    int a = stoi(s.substr(0, s.length() / 2));
    int b = stoi(s.substr(s.length() / 2));
    if (a * b != 0) {
      if (t % (a * b) == 0) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
