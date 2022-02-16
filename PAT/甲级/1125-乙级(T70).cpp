#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  double total = v[0];
  for (int i = 1; i < N; i++) {
    total = (total + v[i]) / 2.0;
  }
  cout << (int)total;
  return 0;
}
