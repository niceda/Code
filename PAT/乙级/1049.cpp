#include <iostream>
using namespace std;

int main()  {
  int n;
  cin >> n;
  long double  sum = 0.0, temp;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    sum = sum + temp * i * (n - i + 1);
  }
  printf("%.2Lf", sum);
  return 0;
}
