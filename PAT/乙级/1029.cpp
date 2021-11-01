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
      if (c.find(toupper(a[i])) == string::npos)
        c += toupper(a[i]);
      i++;
    }
  }
  cout << c;
  return 0;
}
