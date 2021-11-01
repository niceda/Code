#include <iostream>
#include <vector>
using namespace std;

int main() {
  int M, N, TOL, t, x, y;
  cin >> M >> N >> TOL;
  vector<int> v[N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> t;
      v[i].push_back(t);
    }
  }
  vector<int> s;
  for (int i = 1; i < N - 1; i++) {
    for (int j = 1; j < M - 1; j++) {
      if (v[i][j] - v[i][j + 1] > TOL && v[i][j] - v[i][j - 1] > TOL &&
          v[i][j] - v[i + 1][j] > TOL && v[i][j] - v[i - 1][j] > TOL &&
          v[i][j] - v[i + 1][j - 1] > TOL && v[i][j] - v[i + 1][j + 1] > TOL &&
          v[i][j] - v[i - 1][j - 1] > TOL && v[i][j] - v[i - 1][j + 1] > TOL) {
        if (s.size() == 1) {
          cout << "Not Unique";
          return 0;
        }
        s.push_back(v[i][j]);
        x = i + 1;
        y = j + 1;
      }
    }
  }
  if (s.empty())
    cout << "Not Exist";
  else
    printf("(%d, %d): %d", y, x, s[0]);
  return 0;
}
