#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
  int N, M, t1, t2, sum = 0;
  cin >> N;
  map<int, int> m;
  set<int> s, a;
  for (int i = 0; i < N; i++) {
    cin >> t1 >> t2;
    m[t1] = t2;
    m[t2] = t1;
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> t1;
    s.insert(t1);
  }
  for (auto u : s) {
    if (m.find(u) == m.end() || s.find(m[u]) == s.end()) {
      sum++;
      a.insert(u);
    }
  }
  cout << sum << endl;
  for (auto u : a) {
    if (u != *a.begin())
      cout << " ";
    cout << u;
  }
  return 0;
}
