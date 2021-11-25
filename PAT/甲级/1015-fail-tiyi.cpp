#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int n) {
  if (n <= 1) return false;
  int sqr = int(sqrt(n * 1.0));
  for (int i = 2; i <= sqr; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main() {
  int n, d;
  while ((cin >> n)) {
    if (n < 0) {
      break;
    }
    cin >> d;
    if (!isprime(n)) {
      cout << "No" << endl;
      continue;
    } else {
      int len = 0, arr[100];
      do {
        arr[len++] = n % d;
        n = n / d;
      } while (n != 0);
      for (int i = 0; i < len; i++) {
        n = n * d + arr[i];
      }
      if (isprime(n)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
