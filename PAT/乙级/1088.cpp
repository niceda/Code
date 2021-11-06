#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void fuc(int a, int b) {
  if (a > b)
    cout << " Gai";
  else if (a == b)
    cout << " Ping";
  else
    cout << " Cong";
}

int main() {
  int m, x, y, jia, yi, max = -1;
  double bing;
  cin >> m >> x >> y;
  for (int i = 10; i < 100; i++) {
    string s = to_string(i);
    reverse(s.begin(), s.end());
    int temp = std::stoi(s);
    if (abs(i - temp) * y == x * temp && i > max) {
      jia = i;
      yi = temp;
      bing = (double)temp / y;
      max = i;
    }
  }
  if (max == -1)
    cout << "No Solution";
  else {
    cout << jia;
    fuc(m, jia);
    fuc(m, yi);
  if (m > bing)
    cout << " Gai";
  else if (m == bing)
    cout << " Ping";
  else
    cout << " Cong";
  }
  return 0;
}
