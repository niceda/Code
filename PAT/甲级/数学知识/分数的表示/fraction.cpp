#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct Fraction {
  long long up, down;
};

Fraction reduction(Fraction result) {
  if (result.down < 0) {
    result.up = -result.up;
    result.down = -result.down;
  }

  if (result.up == 0) {
    result.down = 1;
  } else {
    int d = gcd(abs(result.up), abs(result.down));
    result.up /= d;
    result.down /= d;
  }
  return result;
}

Fraction add(Fraction f1, Fraction f2) {
  Fraction result;
  result.up = f1.up * f2.down + f2.up * f1.down;
  result.down = f1.down * f2.down;
  return reduction(result);
}

Fraction minu(Fraction f1, Fraction f2) {
  Fraction result;
  result.up = f1.up * f2.down - f2.up * f1.down;
  result.down = f1.down * f2.down;
  return reduction(result);
}

Fraction multi(Fraction f1, Fraction f2) {
  Fraction result;
  result.up = f1.up * f2.up;
  result.down = f1.down * f2.down;
  return reduction(result);
}

Fraction divide(Fraction f1, Fraction f2) {
  Fraction result;
  if (f2.up == 0) {
    // 根据题目特判j
  }
  result.up = f1.up * f2.down;
  result.down = f1.down * f2.up;
  return reduction(result);
}

void showResult(Fraction r) {
  r = reduction(r);
  if (r.down == 1)
    printf("%lld", r.up);
  else if (abs(r.up) > r.down) {
    printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
  } else {
    printf("%lld/%lld", r.up, r.down);
  }
}

int main() { return 0; }
