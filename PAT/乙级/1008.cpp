#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  M %= N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  if (M != 0) {
    reverse(begin(a), begin(a) + N);
    reverse(begin(a), begin(a) + M);
    reverse(begin(a) + M, begin(a) + N);
  }
  for (int i = 0; i < N - 1; i++) {
    if (i != 0) cout << " ";
    cout << a[i];
  }
  return 0;
}
