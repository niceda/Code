#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

struct node {
  int l, r;
};

bool cmp(node a, node b) { return a.l != b.l ? a.l < b.l : a.r < b.r; }

vector<int> v[10000];
vector<int> gendermap(10000);
int flag[10000];
int main() {
  int n, m, k;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[abs(a)].push_back(abs(b));
    v[abs(b)].push_back(abs(a));
    if (a < 0) {
      gendermap[abs(a)] = -1;
    } else {
      gendermap[abs(a)] = 1;
    }
    if (b < 0) {
      gendermap[abs(b)] = -1;
    } else {
      gendermap[abs(b)] = 1;
    }
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a = abs(a);
    b = abs(b);
    vector<node> result;
    for (int j = 0; j < v[a].size(); j++) {
      if (gendermap[a] == gendermap[v[a][j]]) {
        fill(flag, flag + 10000, 0);
        for (int i = 0; i < v[v[a][j]].size(); i++) {
          flag[v[v[a][j]][i]] = 1;
        }
        for (int l = 0; l < v[b].size(); l++) {
          if (gendermap[b] == gendermap[v[b][l]] && flag[v[b][l]] == 1) {
            result.push_back({v[a][j], v[b][l]});
          }
        }
      }
    }
    sort(result.begin(), result.end(), cmp);
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
      cout << result[i].l << " " << result[i].r << endl;
    }
  }
  return 0;
}
