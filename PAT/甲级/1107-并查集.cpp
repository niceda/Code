#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> father, isRoot;
bool cmp(int a, int b) { return a > b; }
int findFather(int x) {
  if (x == father[x])
    return x;
  int a = x;
  while (x != father[x])
    x = father[x];
  while (a != x) {
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
  int n, cnt = 0;
  int course[1001] = {0};
  cin >> n;
  father.resize(n + 1);
  isRoot.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    father[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    int k, t;
    scanf("%d: ", &k);
    for (int j = 0; j < k; j++) {
      cin >> t;
      if (course[t] == 0)
        course[t] = i;
      Union(i, course[t]);
    }
  }
  for (int i = 1; i <= n; i++) {
    isRoot[findFather(i)]++;
  }
  for (int i = 1; i <= n; i++) {
    if (isRoot[i] != 0) {
      cnt++;
    }
  }
  sort(isRoot.begin(), isRoot.end(), cmp);
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++) {
    if (i != 0)
      cout << " ";
    cout << isRoot[i];
  }
  return 0;
}
