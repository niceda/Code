#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, t, max = -1;
  cin >> n >> m;
  vector<int> v(n + 1);
  for (int i = 0; i < m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> t;
      v[j] += t;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (v[i] > max)
      max = v[i];
  }
  cout << max << endl;
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i] == max) {
      if (flag != 0)
        cout << " ";
      cout << i;
      flag = 1;
    }
  }
  return 0;
}
