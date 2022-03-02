#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, k, tmp;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    m[tmp]++;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> tmp;
    if (i != 0) cout << " ";
    cout << m[tmp];
  }
  return 0;
}
