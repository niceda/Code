#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  int c = 0, r, total = 0;
  for (int i = 0; i < n; i++) {
    cin >> r;
    if (r > c) {
      total += (r - c) * 6 + 5;
    } else {
      total += (c - r) * 4 + 5;
    }
    c = r;
  }
  cout << total;
  return 0;
}
