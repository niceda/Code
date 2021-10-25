#include <iostream>
using namespace std;

int main() {
  int g1, s1, k1, g2, s2, k2;
  char c;
  cin >> g1 >> c >> s1 >> c >> k1 >> g2 >> c >> s2 >> c >> k2;
  int a = (g2 * 17 + s2) * 29 + k2 - (g1 * 17 + s1) * 29 - k1;
  if (a < 0) {
    cout << '-';
    a = abs(a);
  }
  cout << (a / 29) / 17 << '.' << (a / 29) % 17 << '.' << a % 29;
  return 0;
}
