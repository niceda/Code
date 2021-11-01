#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N, max = -1;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (int i = 0, j = 0; i <= N && j < N; i++) {
    for (; j < N; j++) {
      if (v[j] >= i + 1) {
        if (N - j >= i) {
          max = i;
          break;
        }
        else
          break;
      }
    }
    if (N - j < i)
      break;
  }
  cout << max;
  return 0;
}
