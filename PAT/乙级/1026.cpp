#include <iostream>
using namespace std;

int main() {
  int c1, c2, t, a, b, c;
  cin >> c1 >> c2;
  t = (c2 - c1) % 100;
  if (t >= 50)
    t = (c2 -c1) / 100 + 1;
  else 
    t = (c2 -c1) / 100;
  a = t % 60;
  t = t / 60;
  b = t % 60;
  t = t / 60;
  c = t % 60;
  t = t / 60;
  printf("%02d:%02d:%02d", c, b, a);
  return 0;
}
