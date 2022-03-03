#include <iostream>
using namespace std;

int Msize, N, M, hashtable[10010];
bool isPrime(int a) {
  if (a <= 1) return false;
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}

void insert(int key) {
  for (int step = 0; step < Msize; step++) {
    if (hashtable[(key + step * step) % Msize] == 0) {
      hashtable[(key + step * step) % Msize] = key;
      return;
    }
  }
  printf("%d cannot be inserted.\n", key);
}

int search(int key) {
  int cnt = 0;
  for (int step = 0; step <= Msize; step++) {
    cnt++;
    if (hashtable[(key + step * step) % Msize] == key ||
        hashtable[(key + step * step) % Msize] == 0) {
      break;
    }
  }
  return cnt;
}
int main() {
  scanf("%d %d %d", &Msize, &N, &M);
  while (!isPrime(Msize)) Msize++;
  for (int i = 0; i < N; i++) {
    int t;
    scanf("%d", &t);
    insert(t);
  }
  int cnt = 0;
  for (int i = 0; i < M; i++) {
    int t;
    scanf("%d", &t);
    cnt += search(t);
  }
  printf("%.1lf", (double)cnt / M);
  return 0;
}