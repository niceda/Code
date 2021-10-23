#include <cctype>
#include <iostream>
using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b;
  for (int i = 0, j = 0; i < a.length();) {
    if (a[i] == b[j]) {
      i++;
      j++;
    } else {

      // if (c.empty()) {
      //   c.push_back(toupper(a[i]));
      // } else {
      //   for (int k = 0; k < c.length(); k++) {
      //     if (toupper(c[k]) != toupper(a[i]) && k != c.length() - 1)
      //       continue;
      //     else if (toupper(c[k]) != toupper(a[i]) && k == c.length() - 1)
      //       c.push_back(toupper(a[i]));
      //     else
      //       break;
      //   }
      // }

      if (c.find(toupper(a[i])) == string::npos)
        c.push_back(toupper(a[i]));
      i++;
    }
  }
  cout << c;
  return 0;
}
