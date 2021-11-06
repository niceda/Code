#include <iostream>
using namespace std;

int main() {
  char c, t;
  string s;
  cin >> c;
  getchar();
  getline(cin, s);
  if (c == 'C') {
    int sum = 0;
    t = s[0];
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == t && i != s.length() - 1) {
        sum++;
      } else if (sum == 1) {
        cout << t;
        t = s[i];
      } else if (sum > 1) {
        cout << sum << t;
        sum = 1;
        t = s[i];
      }
      if (i == s.length() - 1 && s[i] != s[i - 1])
        cout << s[i];
    }
  }
  if (c == 'D') {
    int flag = 0, temp = 1;
    for (int i = 0, j = 0; i < s.length(); i++) {
      if (isdigit(s[i])) {
        if (flag == 0) {
          j = i;
          flag = 1;
        }
        continue;
      } else {
        if (flag == 1) {
          string tt = s.substr(j, i - j);
          temp = std::stoi(tt);
        }
        for (int l = 0; l < temp; l++) {
          cout << s[i];
        }
        temp = 1;
        flag = 0;
      }
    }
  }
  return 0;
}
