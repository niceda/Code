#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

const int inf = 999999999;
int e[201][201];

int main() {
  int n, m, k;
  cin >> n >> m;
  fill(e[0], e[0] + 201 * 201, inf);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    e[a][b] = e[b][a] = 1;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int isclique = 1, ismaximalclique = 1;
    int l;
    cin >> l;
    vector<int> v;
    vector<int> flag(n+1);
    for (int j = 0; j < l; j++) {
      int t;
      cin >> t;
      flag[t] = 1;
      for (int z = 0; z < v.size() && isclique == 1; z++) {
        if (e[v[z]][t] == inf) {
          isclique = 0;
          break;
        }
      }
      v.push_back(t);
    }
    if (isclique == 1) {
      for (int i = 1; i <= n && ismaximalclique == 1; i++) {
        if (flag[i] == 0) {
          int judge = 0;
          for (int j = 0; j < v.size(); j++) {
            if (e[v[j]][i] == inf) {
              judge = 1;
              break;
            }
          }
          if (judge == 0) {
            ismaximalclique = 0;
          }
        }
      }
      if (ismaximalclique == 1) {
        cout << "Yes" << endl;
      } else {
        cout << "Not Maximal" << endl;
      }
    } else if (isclique == 0) {
      cout << "Not a Clique" << endl;
    }
  }
  return 0;
}
