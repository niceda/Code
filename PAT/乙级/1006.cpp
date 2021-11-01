#include <iostream>
using namespace std;

int main() {
  int n, i = 0;
  cin >> n;
  int b[3] = {0};
  while (n != 0) {
    b[i++] = n % 10;
    n = n / 10;
  }
  for (int i = 0; i < b[2]; i++) {
    cout << "B";
  }
  for (int i = 0; i < b[1]; i++) {
    cout << "s";
  }
  for (int i = 0; i < b[0]; i++) {
    cout << i + 1;
  }
  return 0;
}
