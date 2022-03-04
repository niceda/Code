#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> prime1(500000, 1);

const int maxn = 101;
int prime2[maxn], pNum = 0;
bool p[maxn] = {true};
void Find_Prime2() {
  for (int i = 2; i < maxn; i++) {
    if (p[i] == true) {
      prime1[pNum++] = i;
      for (int j = i + i; j < maxn; j += i) {
        p[j] = false;
      }
    }
  }
}

int main() {
  for (int i = 2; i * i < 500000; i++) {
    for (int j = 2; i * j < 500000; j++) {
      prime1[i * j] = 0;
    }
  }

  memset(p, 1, maxn);
  Find_Prime2();
  for (int i = 0; i < pNum; i++) {
    printf("%d ", prime2[i]);
  }
  return 0;
}
