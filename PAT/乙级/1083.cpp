#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, temp;
  cin >> n;
  map<int, int> m;
  for (int i = 1; i < n+1; i++) {
    cin >> temp;
    m[abs(temp - i)]++;
  }
  for (auto it = m.rbegin(); it != m.rend(); it++) {
    if (it->second > 1)
      cout << it->first << " " << it->second << endl;
  }
  return 0;
}
