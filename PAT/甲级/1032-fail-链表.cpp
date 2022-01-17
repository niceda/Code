#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int start, end, n;
  cin >> start >> end >> n;
  vector<int> pre[100000];
  int ad, nt, flag = 0;
  char data;
  for (int i = 0; i < n; i++) {
    cin >> ad >> data >> nt;
    if (nt == -1 && flag == 0) {
      flag = 1;
      continue;
    } else if (nt == -1 && flag == 1) {
      cout << "-1";
      return 0;
    }
    if (pre[nt].size() >= 1) {
      printf("%05d", nt);
      return 0;
    }
    pre[nt].push_back(ad);
  }
  cout << "-1";
  return 0;
}
