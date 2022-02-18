#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n, m, a, b;
  map<int, vector<int>> ma;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    ma[a].push_back(b);
    ma[b].push_back(a);
  }
  while (m--) {
    int t, flag = 0, a[100000] = {0};
    scanf("%d", &t);
    vector<int> v(t);
    for (int i = 0; i < t; i++) {
      cin >> v[i];
      a[v[i]] = 1;
    }
    for (int i = 0; i < v.size(); i++)
      for (int j = 0; j < ma[v[i]].size(); j++)
        if (a[ma[v[i]][j]] == 1)
          flag = 1;
    printf("%s\n", flag ? "No" : "Yes");
  }
  return 0;
}
