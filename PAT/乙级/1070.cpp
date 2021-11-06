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
  double result = v[0];
  for (int i = 1; i < N; i++) {
    result = (result + v[i]) / 2.0;
  }
  cout << (int)result;
  return 0;
}
