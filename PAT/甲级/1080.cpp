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
  int ge, gi, rank, id;
  int choice[5];
};

bool cmp(node a, node b) {
  return a.ge + a.gi != b.ge + b.gi ? a.ge + a.gi > b.ge + b.gi : a.ge > b.ge;
}
vector<int> result[100];
vector<int> lastrank(100);

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<node> v(n);
  vector<int> quota(m);
  for (int i = 0; i < m; i++) {
    cin >> quota[i];
  }
  for (int i = 0; i < n; i++) {
    v[i].id = i;
    cin >> v[i].ge >> v[i].gi;
    for (int j = 0; j < k; j++) {
      cin >> v[i].choice[j];
    }
  }
  sort(v.begin(), v.end(), cmp);
  v[0].rank = 1;
  for (int i = 1; i < n; i++) {
    if (v[i].ge + v[i].gi == v[i - 1].ge + v[i - 1].gi &&
        v[i].ge == v[i - 1].ge) {
      v[i].rank = v[i - 1].rank;
    } else {
      v[i].rank = i + 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      if (v[i].rank == lastrank[v[i].choice[j]]) {
        result[v[i].choice[j]].push_back(v[i].id);
        break;
      } else if (result[v[i].choice[j]].size() < quota[v[i].choice[j]]) {
        result[v[i].choice[j]].push_back(v[i].id);
        lastrank[v[i].choice[j]] = v[i].rank;
        break;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    sort(result[i].begin(), result[i].end());
    for (int j = 0; j < result[i].size(); j++) {
      if (j != 0)
        cout << " ";
      cout << result[i][j];
    }
    cout << endl;
  }
  return 0;
}
