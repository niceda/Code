#include <iostream>
using namespace std;

int main() {
  string v[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  string s;
  long total = 0;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    total += s[i] - '0';
  }
  s = to_string(total);
  for (int i = 0; i < s.length(); i++) {
    if (i != 0) cout << " ";
    cout << v[s[i] - '0'];
  }
  return 0;
}
