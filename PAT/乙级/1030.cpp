#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long p;
  cin >> N >> p;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int result = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + result; j < N; j++) {
      if (v[j] <= p * v[i])
        result += 1;
      else {
        break;
      }
    }
  }
  cout << result;
  return 0;
}
