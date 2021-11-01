#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int t = (a - b + 50) / 100;
  int hour = t / 3600;
  t = t % 3600;
  int minute = t / 60, second = t % 60;
  printf("%02d:%02d:%02d", hour, minute, second);
  return 0;
}
