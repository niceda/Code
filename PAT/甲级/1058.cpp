#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int a1, b1, c1, a2, b2, c2, carry;
  scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
  int c3 = (c1 + c2) % 29;
  carry = (c1 + c2) / 29;
  int b3 = (b1 + b2 + carry) % 17;
  carry = (b1 + b2 + carry) / 17;
  int a3 = (a1 + a2 + carry);
  printf("%d.%d.%d", a3, b3, c3);
  return 0;
}
