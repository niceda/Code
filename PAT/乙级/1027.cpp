#include <iostream>
using namespace std;

int main() {
  int n, r, a = 1, flag = 0;
  char x;
  cin >> n >> x;
  int t = n / 2;
  while (t - (a + 2) >= 1) {
    a += 2;
    t -= a;
  }
  int j = 0;
  for (int i = a; i > 0;) {
    for(int m = j; m > 0; m--)
      cout << " ";
    for (int k = i; k > 0; k--)
      cout << x;
    cout << endl;
    j++;
    i -= 2;
  }
  j = j -2;
  for (int i = 3; i <= a;) {
    for(int m = j; m > 0; m--)
      cout << " ";
    for (int k = i; k > 0; k--)
      cout << x;
    cout << endl;
    j--;
    i += 2;
  }
  r = n - (1 + a) * (1 + a) / 2 + 1;
  cout << r;
  return 0;
}
