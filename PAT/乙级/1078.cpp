#include <iostream>
using namespace std;

int main() {
  char c, t;
  string s;
  cin >> c;
  getchar();
  getline(cin, s);
  if (c == 'C') {
    int cnt = 0, j = 0;
    char pres;
    string s1, s2;
    for (int i = 0; i < s.length(); i = j) {
      pres = s[i];
      for (j = i; j < s.length() && pres == s[j]; j++) {
        if (j > i)
          s2 = to_string(j - i + 1) + pres;
        else
          s2 = pres;
      }
      s1 = s1 + s2;
    }
    cout << s1;
  }
  if (c == 'D') {
    string num;
    int cnt = 1;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] >= '0' && s[i] <= '9')
        num += s[i];
      else {
        if (num.length() > 0) cnt = stoi(num);
        while(cnt--) cout << s[i];
        cnt = 1;
        num = "";
      }
    }
  }
  return 0;
}
