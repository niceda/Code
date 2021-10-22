#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
  int k, flag = 0;
  cin >> k;
  map<int, int> m;
  for (int i = 0; i < k; i++) {
    int n;
    cin >> n;
    auto it = m.find(n);
    if (it != m.end())
      continue;
    m[n] = 0;
    while (n != 1) {
      if (n % 2 != 0)
        n = 3 * n + 1;
      n = n / 2;
      if (m.find(n) == m.end()) 
        m[n] = 1;
      else if (m[n] == 0) 
        m[n] = 1;
      else
        break;
    }
  }
  for (auto it = m.rbegin(); it != m.rend(); it++) {
    if (it->second == 0) {
      if (flag != 0)
        cout << " ";
      cout << it->first;
      flag = 1;
    }
  }
  return 0;
}
