#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> score(M), right(M), total(M);
  for (int i = 0; i < M; i++) {
    cin >> score[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> right[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int temp;
      cin >> temp;
      if (temp == right[j])
        total[i] += score[j];
    }
  }
  for (int i = 0; i < N; i++) {
    cout << total[i] << endl;
  }
  return 0;
}
