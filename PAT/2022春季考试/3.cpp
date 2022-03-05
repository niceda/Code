#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int n, flag = 1;
vector<int> v;
void dfs(int index, int min, int max) {
  if (index >= n || v[index] == -1) return;
  if ((2 * index + 1 < n && v[2 * index + 1] != -1 &&
       v[index] <= v[2 * index + 1] && v[2 * index + 1] >= min) ||
      (2 * index + 2 < n && v[2 * index + 2] != -1 &&
       v[index] > v[2 * index + 2] && v[2 * index + 2] < max)) {
    flag = 0;
    return;
  }
  dfs(2 * index + 1, min, v[index]);
  dfs(2 * index + 2, v[index], max);
}

int flag2 = 0;
void inorder(int index) {
  if (index >= n || v[index] == -1) return;
  inorder(2 * index + 1);
  if (flag2 != 0) cout << " ";
  cout << v[index];
  flag2 = 1;
  inorder(2 * index + 2);
}

int main() {
  scanf("%d", &n);
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  dfs(0, -999999999, -999999999);
  if (flag == 1)
    printf("YES\n");
  else
    printf("NO\n");
  inorder(0);
}