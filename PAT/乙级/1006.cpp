#include <iostream>
using namespace std;

int main() {
  int n, ge, shi, bai;
  cin >> n;
  ge = n % 10;
  string B;
  string S;
  string G = "";
  for (int i = 1; i < ge + 1; i++) {
    G += to_string(i);
  }
  int n1 = n / 10;
  if (n1 != 0) {
    shi = n1 % 10;
    S.append(shi, 'S');
  }
  int n2 = n1 / 10;
  if (n2 != 0) {
    bai = n2 % 10;
    B.append(bai, 'B');
  }
  if(n2 != 0)
    cout << B + S + G;
  else if (n1 != 0)
    cout << S + G;
  else
    cout << G;
}
