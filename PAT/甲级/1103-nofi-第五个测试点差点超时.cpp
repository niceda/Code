#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int n, k, p;
vector<int> temp;
vector<vector<int>> result;
void gen(int n, int cnt) {
  if (temp.size() > k || (temp.size() < k && n == 0) || n < k - temp.size()) {
    return;
  } else if (n == 0 && temp.size() == k) {
    vector<int> t = temp;
    sort(t.begin(), t.end(), greater<int>());
    result.push_back(temp);
    return;
  }
  for (int i = cnt; pow(i, p) <= n; i++) {
    temp.push_back(i);
    gen(n - pow(i, p), i);
    temp.pop_back();
  }
}

bool cmp(vector<int> &a, vector<int> &b) {
  int suma = 0, sumb = 0;
  for (int i = 0; i < k; i++) {
    suma += a[i];
    sumb += b[i];
  }
  if (suma != sumb) {
    return suma > sumb;
  } else {
    for (int i = 0; i < k; i++) {
      if (a[i] != b[i])
        return a[i] > b[i];
    }
  }
}

int main() {
  scanf("%d %d %d", &n, &k, &p);
  gen(n, 1);
  for (int i = 0; i < result.size(); i++) {
    sort(result[i].begin(), result[i].end(), greater<int>());
  }
  sort(result.begin(), result.end());
  if (!result.empty()) {
    printf("%d =", n);
    for (int i = 0; i < k; i++) {
      if (i != 0)
        cout << " +";
      printf(" %d^%d", result[0][i], p);
    }
  } else {
    cout << "Impossible";
  }
  return 0;
}
