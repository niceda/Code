#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

const int maxn = 101;
int prime[maxn], pNum = 0;
bool p[maxn] = {1};
void Find_Prime() {
  for (int i = 2; i < maxn; i++) {
    if (p[i] == true) {
      prime[pNum++] = i;
      for (int j = i + i; j < maxn; j += i) {
        p[j] = false;
      }
    }
  }
}

int main() {
  Find_Prime();
  for (int i = 0; i < pNum; i++) {
    printf("%d ", prime[i]);
  }
  return 0;
}
