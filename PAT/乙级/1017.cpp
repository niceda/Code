#include <iostream>
using namespace std;

int main() {
  string a, q;
  int b, r = 0, flag = 0;
  cin >> a >> b;
  for (int i = 0; i < a.length(); i++) {
    r = r * 10 + a[i] - '0';
    q.push_back(r / b + '0');
    r = r % b;
  }
  for (int i = 0; i < q.length(); i++) {
    if (q[i] == '0' && flag == 0) 
      continue;
    else {
      cout << q[i];
      flag = 1;
    }
  }
  if (flag == 0) cout << '0';
  cout << " " << r;
  return 0;
}
