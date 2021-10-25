#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, k, tmp, flag = 0;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    m[tmp]++;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> tmp;
    if (flag != 0) cout << " ";
    cout << m[tmp];
    flag = 1;
  }
  return 0;
}
