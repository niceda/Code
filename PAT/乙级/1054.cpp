#include <cctype>
#include <iostream>
using namespace std;

int func(string s) {
  if (s.length() > 7 || (!isdigit(s[0]) && s[0] != '-'))
    return 0;
  int flag = 0;
  for (int i = 0, num1 = 0, num2 = 0; i < s.length(); i++) {
    if (isdigit(s[i]) && flag == 0 && num1 < 3) {
      num1++;
      continue;
    }
    if (isdigit(s[i]) && flag == 1 && num2 < 2) {
      num2++;
    } else if (s[0] == '-')
      continue;
    else if (s[i] == '.' && i < s.length() - 1 && flag == 0) {
      flag = 1;
      continue;
    } else
      return 0;
  }
  return 1;
}

int main() {
  int n, cnt = 0;
  double sum = 0.0;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (!func(s))
      cout << "ERROR: " << s << " is not a legal number" << endl;
    else {
      cnt++;
      sum += stof(s);
    }
  }
  if (cnt == 1)
    printf("The average of 1 number is %.2f", sum);
  else if (cnt > 1)
    printf("The average of %d numbers is %.2f", cnt, sum / cnt);
  else
    printf("The average of 0 numbers is Undefined");
  return 0;
}
