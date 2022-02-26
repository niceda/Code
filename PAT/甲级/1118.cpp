#include <iostream>
#include <vector>
#include <set>
using namespace std;

int father[10000];
int findFather(int x) {
  int a = x;
  if (x == father[x]) {
    return x;
  }
  while (x != father[x]) {
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
  if (faA != faB) {
    father[faA] = faB;
  }
}

int main() {
  int n, k, maxnum = -1, cnt = 0;
  set<int> s;
  scanf("%d", &n);
  for (int i = 0; i < 10000; i++) {
    father[i] = i;
  }
  for (int i = 0; i < n; i++) {
    int root, t;
    scanf("%d %d", &k, &root);
    if (root > maxnum) {
      maxnum = root;
    }
    for (int j = 1; j < k; j++) {
      scanf("%d", &t);
      Union(root, t);
      if (t > maxnum) {
        maxnum = t;
      }
    }
  }
  for (int i = 1; i <= maxnum; i++) {
    s.insert(findFather(i));
  }
  scanf("%d", &k);
  printf("%d %d\n", (int)s.size(), maxnum);
  for (int i = 0; i < k; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (findFather(a) != findFather(b)) {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
  }
  return 0;
}

