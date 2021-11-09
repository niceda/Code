#include <iostream>
using namespace std;

int main() {
  string str[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
  string s;
  cin >> s;
  long sum = 0;
  for (int i = 0; i < s.length(); i++) {
    sum += s[i] - '0';
  }
  string t = to_string(sum);
  for (int i = 0; i < t.length(); i++) {
    if (i != 0) cout << " ";
    cout << str[t[i] - '0'];
  }
  return 0;
}
