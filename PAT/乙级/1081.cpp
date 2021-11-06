#include <cctype>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  getchar();
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    if (s.length() < 6) {
      cout << "Your password is tai duan le." << endl;
      continue;
    }
    int flag1 = 0, flag2 = 0, flag3 = 0;
    for (int i = 0; i < s.length(); i++) {
      if (!isdigit(s[i]) && !isalpha(s[i]) && s[i] != '.') {
        flag1 = 1;
        break;
      } else if (isdigit(s[i]))
        flag2 = 1;
      else if (isalpha(s[i]))
        flag3 = 1;
    }
    if (flag1 == 1)
      cout << "Your password is tai luan le." << endl;
    else if (flag2 == 0)
      cout << "Your password needs shu zi." << endl;
    else if (flag3 == 0)
      cout << "Your password needs zi mu." << endl;
    else
     cout << "Your password is wan mei." << endl;
    flag1 = 0, flag2 = 0, flag3 = 0;
  }
  return 0;
}
