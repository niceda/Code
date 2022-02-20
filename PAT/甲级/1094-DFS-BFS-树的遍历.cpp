#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

vector<int> v[100];
int num, maxlevel;
vector<int> levelnum(100);

void BFS(int root, int level) {
  levelnum[level + 1] += v[root].size();
  if (levelnum[level + 1] > num) {
    num = levelnum[level + 1];
    maxlevel = level + 1;
  }
  for (int i = 0; i < v[root].size(); i++) {
    BFS(v[root][i], level + 1);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  int root, k, t;
  for (int i = 0; i < m; i++) {
    cin >> root >> k;
    for (int j = 0; j < k; j++) {
      cin >> t;
      v[root].push_back(t);
    }
  }

  levelnum[1] = 1;
  num = 1, maxlevel = 1;
  BFS(1, 1);
  cout << num << " " << maxlevel;
  return 0;
}
