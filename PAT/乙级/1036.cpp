#include <iostream>
using namespace std;

int main() {
  int n, flag = 0;
  char a;
  cin >> n >> a;
  int l = (n / 2) + (n % 2);
  for (int i = 0; i < l; i++) {
    if(flag != 0) cout << endl;
    if (i == 0 || i == l - 1) {
      for (int j = 0; j < n; j++) {
        cout << a;
      }
      flag = 1;
      continue;
    }
    for (int j = 0; j < n; j++) {
      if(j ==0 || j == n - 1)
        cout << a;
      else
        cout << " ";
    }
  }
    return 0;
}
