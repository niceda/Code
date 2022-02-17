#include <iostream>
using namespace std;

int main() {
  int N, D, k, a = 0, b = 0;
  double e, temp;
  cin >> N >> e >> D;
  for (int i = 0; i < N; i++) {
    int total = 0;
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> temp;
      if (temp < e)
        total++;
    }
    if(total > (k / 2))
      k > D ? b++ : a++;
  }
  printf("%.1f%% %.1f%%", (double)a / N * 100, (double)b / N * 100);
  return 0;
}
