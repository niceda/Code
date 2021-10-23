#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> v(N + 1);
  for (int i = 1; i < N + 1; i++) {
    int t, score;
    cin >> t >> score;
    v[t] += score;
  }
  int maxt = 1, maxscore = v[1];
  for (int i = 1; i < N + 1; i++) {
    if (v[i] > maxscore) {
      maxt = i;
      maxscore = v[i];
    }
  }
  cout << maxt << " " << maxscore;
  return 0;
}
