#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int v[100000];
int postion[100000];

int main() {
  int n, cnt = 0, flag = 0;
  set<int> s;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    postion[v[i]] = i;
    if (v[i] != i && v[i] != 0) s.insert(v[i]);
  }
  while (postion[0] != 0 || flag != 1) {
    if (postion[0] != 0) {
      int tp;
      s.erase(postion[0]);
      tp = postion[postion[0]];
      v[tp] = 0; 
      v[postion[0]] = postion[0];
      postion[postion[0]] = postion[0];
      postion[0] = tp;
      cnt++;
    } else {
      if (!s.empty()) {
        int index = postion[*s.begin()], t;
        s.erase(s.begin());
        t = v[index];
        v[0] = t;
        v[index] = 0;
        postion[0] = index;
        postion[t] = 0;
        cnt++;
      } else {
        flag = 1;
      }
    }
  }
  printf("%d", cnt);
  return 0;
}
