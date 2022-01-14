#include <iostream>
#include <vector>
using namespace std;

int main() {
  float a, b, c, total = 1;
  char r[3];
  for (int i = 0; i < 3; i++) {
    cin >> a >> b >> c;
    if (a >= b) {
      if (a >= c) {
        cout << 'W';
      } else {
        cout << 'L';
      }
    } else if (b >= c) {
      cout << 'T';
    } else {
      cout << 'L';
    }
    total *= max(max(a, b), c);
  }
  printf(" %.2f", (total * 0.65 - 1) * 2);
  return 0;
}
