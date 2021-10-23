#include <iostream>
using namespace std;

string fun(int a, int b) {
  string s;
  if (a < b || a > -b) {
  }
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int a, b, c, d;
  if (s1.length() == 4) {
    a = -(s1[1] - '0');
    b = (s1[3] - '0');
  } else {
    a = (s1[0] - '0');
    b = (s1[2] - '0');
  }
  if (s2.length() == 4) {
    c = -(s2[1] - '0');
    d = (s2[3] - '0');
  } else {
    c = (s2[0] - '0');
    d = (s2[2] - '0');
  }

  if ((a * d + b * c) < 0) {
  }
  int result11 = (a * d + b * c) / (b * d);
  int result12 = abs((a * d + b * c) % (b * d));

  int result21 = (a * d - b * c) / (b * d);
  int result22 = abs((a * d - b * c) % (b * d));

  int result31 = (a * c) / (b * d);
  int result32 = (a * c) % (b * d);
  return 0;
}
