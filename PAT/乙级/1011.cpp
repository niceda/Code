#include <iostream>
using namespace std;

int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    long long int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    bool b = num1 + num2 > num3;
    printf("Case #%d: %s\n", i + 1, b ? "true" : "false");
  }
}
