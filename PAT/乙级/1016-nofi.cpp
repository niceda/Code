#include <iostream>
using namespace std;

int main() {
  string a, b;
  int da, db, cnta = 0, cntb = 0, pa = 0, pb = 0;
  cin >> a >> da >> b >> db;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] - '0' == da)
      cnta++;
  }
  for (int i = 0; i < b.length(); i++) {
    if (b[i] - '0' == db)
      cntb++;
  }
  if (cnta != 0)
    pa = da;
  if (cntb != 0)
    pb = db;
  for (int i = 1; i < cnta; i++) {
    pa = 10 * pa + da;
  }
  for (int i = 1; i < cntb; i++) {
    pb = 10 * pb + db;
  }
  cout << pa + pb;
  return 0;
}
