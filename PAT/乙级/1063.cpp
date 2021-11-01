#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N, a, b;
  float max = -1;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    float t = sqrt((a * a)+ (b * b));
    if (t > max)
      max = t;
  }
  printf("%.2f", max);
  return 0;
}
