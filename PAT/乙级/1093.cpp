#include <iostream>
#include <set>
using namespace std;

int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  set<char> sc;
  for (int i = 0; i < a.length(); i++) {
    if (sc.find(a[i]) == sc.end()) {
      cout << a[i];
      sc.insert(a[i]);
    }
  }
  for (int i = 0; i < b.length(); i++) {
    if (sc.find(b[i]) == sc.end()) {
      cout << b[i];
      sc.insert(b[i]);
    }
  }
  return 0;
}
