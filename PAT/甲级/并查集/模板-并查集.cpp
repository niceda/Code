#include <iostream>
#include <vector>
using namespace std;

int father[10000];
int findFather(int x) {
  int a = x;
  if (x == father[x]) {
    return x;
  }
  while(x != father[x]) {
    x = father[x];
  }
  while(a != x) {
    int z = a;
    a = father[a];
    father[z] = x;
  }
  return x;
}

void Union(int a, int b) {
  int faA = findFather(a);
  int faB = findFather(b);
  if (faA != faB)
    father[faA] = faB;
}

int main() {
  for (int i = 0; i < 10000; i++) {
    scanf("%d", &father[i]);
  }
}
