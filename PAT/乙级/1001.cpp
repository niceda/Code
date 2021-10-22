#include <iostream>
using namespace std;

int main() {
  int n;
  int i = 0;
  cin >> n;
  int tmp = n % 2;
  while (n != 1) {
    if (tmp) {
      n = (3 * n + 1) / 2;
    } else {
      n = n / 2;
    }
    tmp = n % 2;
    i++;
  }
  cout << i;
}

// LN
/* #include <iostream> */
/* using namespace std; */

/* int main() { */
/*   int n, count = 0; */
/*   cin >> n; */
/*   while (n != 1) { */
/*     if (n % 2 != 0) */
/*       n = 3 * n + 1; */
/*     n = n / 2; */
/*     count++; */
/*   } */
/*   cout << count; */
/* } */
