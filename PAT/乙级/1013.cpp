#include <cmath>
#include <iostream>
using namespace std;

bool isprime(int n) {
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;
  return true;
}

int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 0, j = 2; i < n; j++) {
    if (isprime(j)) {
      if (i >= m - 1) {
        if (i - m + 1 != 0 && (i + 1 - m) % 10 != 0)
          cout << " ";
        if (i - m + 1 != 0 && (i + 1 - m) % 10 == 0)
          cout << endl << j;
        else
          cout << j;
      }
      i++;
    }
  }
}
