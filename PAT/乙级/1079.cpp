#include <algorithm>
#include <iostream>
using namespace std;

bool ispdnum(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != s[s.length() - i - 1])
      return false;
  }
  return true;
};

int main() {
  string s;
  int n = 10;
  cin >> s;
  while (!ispdnum(s) && n--) {
    string sre = s, temp;
    reverse(sre.begin(), sre.end());
    int carry = 0, a;
    for (int i = s.length() - 1; i >= 0; i--) {
      a = (s[i] - '0' + sre[i] - '0' + carry) % 10;
      carry = (s[i] - '0' + sre[i] - '0' + carry) / 10;
      temp.push_back(a + '0');
    }
    if (carry == 1)
      temp = temp + '1';
    reverse(temp.begin(), temp.end());
    cout << s << " + " << sre << " = " << temp << endl;
    s = temp;
    n++;
  }
  if (n == 10)
    cout << "Not found in 10 iterations.";
  else
    cout << s << " is a palindromic number.";
  return 0;
}
