#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a, b, temp, flag = 0;
  cin >> a >> b;
  temp = a * b;
  string s = to_string(temp);
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0' && flag == 0) {
      continue;
    }
    flag = 1;
    cout << s[i];
  }
  return 0;
}
