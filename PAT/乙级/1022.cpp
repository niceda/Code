#include <iostream>
using namespace std;

int main() {
  long int a, b;
  int d;
  cin >> a >> b >> d;
  long int total = a + b;
  string s;
  while (total != 0) {
    int r = total % d;
    total = total / d;
    s.insert(0, 1, r + '0');
  }
  if (s.empty())
    cout << '0';
  cout << s;
}
