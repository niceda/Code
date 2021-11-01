#include <iostream>
using namespace std;

int main() {
  int N, M, A, B, T, t;
  scanf("%d %d %d %d %d", &M, &N, &A, &B, &T);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &t);
      if (t <= B && t >= A)
        t = T;
      if (j != 0)
        cout << " ";
      printf("%03d", t);
    }
    printf("\n");
  }
  return 0;
}
