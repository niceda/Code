#include <iostream>
using namespace std;

int main() {
  int N, sum = 0;
  cin >> N;
  int v[N];
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      sum += v[i] * 10 + v[j] + v[j] * 10 + v[i];
    }
  }
  cout << sum;
  return 0;
}
