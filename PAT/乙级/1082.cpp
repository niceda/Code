#include <iostream>
using namespace std;

int main() {
  int n, max = -1, min = 20001, x, y;
  string firstid, lastid, t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t >> x >> y;
    int temp = x * x + y * y;
    if (temp < min) {
      firstid = t;
      min = temp;
    }
    if (temp > max) {
      lastid = t;
      max = temp;
    }
  }

  cout << firstid << " " << lastid;
  return 0;
}
