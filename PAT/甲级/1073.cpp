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
  if (s[0] == '-') {
    cout << '-';
  }
  int index = 1;
  while (s[index] != 'E') {
    index++;
  }
  string result = s.substr(1, index - 1);
  result.erase(1, 1);
  int e = stoi(s.substr(index + 2));
  if (s[index + 1] == '+') {
    if (result.length() - 1 > e) {
      result.insert(e + 1, ".");
    } else {
      result.append(e - result.length() + 1, '0');
    }
  } else if (s[index + 1] == '-') {
    result.insert(0, e, '0');
    result.insert(1, ".");
  }
  cout << result;
  return 0;
}
