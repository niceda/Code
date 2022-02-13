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
  if (n == 0) {
    cout << "0000 - 0000 = 0000";
    return 0;
  }
  while (n != 6174 && n != 0) {
    string s1 = to_string(n);
    string s2 = to_string(n);
    sort(s1.begin(), s1.end(), greater<char>());
    sort(s2.begin(), s2.end());
    n = stoi(s1) - stoi(s2);
    cout << s1 << " - " << s2 << " = ";
    printf("%04d\n", n);
  }
  return 0;
}
