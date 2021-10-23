#include <cctype>
#include <iostream>
using namespace std;

int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  for (int i = 0; i < a.length(); i++) {
    for (int pos = b.find(a[i]); pos != string::npos;) {
      b.erase(pos, 1);
      pos = b.find(a[i], pos);
    }
    for (int pos = b.find(tolower(a[i])); pos != string::npos;) {
      b.erase(pos, 1);
      pos = b.find(tolower(a[i]), pos);
    }
    if (a[i] == '+') {
      for (int i = 0; i < b.length();) {
        if (b[i] >= 'A' && b[i] <= 'Z')
          b.erase(i, 1);
        else
          i++;
      }
    }
  }
  cout << b;
  return 0;
}
