#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
  int weight;
  vector<int> child;
};
vector<node> v;
vector<vector<int>> path;
vector<int> temppath;
bool cmp(vector<int> a, vector<int> b) {
  for (int i = 0; i < min(a.size(), b.size()); i++) {
    if (v[a[i]].weight != v[b[i]].weight)
      return v[a[i]].weight > v[b[i]].weight;
  }
  return true;
}
long long s;
int n, m;
void DFS(int root) {
  temppath.push_back(root);
  if (v[root].child.empty()) {
    long long sum = 0;
    for (int i = 0; i < temppath.size(); i++) {
      sum += v[temppath[i]].weight;
    }
    if (sum == s)
      path.push_back(temppath);
    temppath.pop_back();
    return;
  }
  for (int i = 0; i < v[root].child.size(); i++) {
    DFS(v[root].child[i]);
  }
  temppath.pop_back();
  return;
}

int main() {
  cin >> n >> m >> s;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].weight;
  }
  for (int i = 0; i < m; i++) {
    int node, k, t;
    cin >> node >> k;
    for (int j = 0; j < k; j++) {
      cin >> t;
      v[node].child.push_back(t);
    }
  }
  DFS(0);
  sort(path.begin(), path.end(), cmp);
  for (int i = 0; i < path.size(); i++) {
    for (int j = 0; j < path[i].size(); j++) {
      if (j != 0)
        cout << " ";
      cout << v[path[i][j]].weight;
    }
    cout << endl;
  }
  return 0;
}
