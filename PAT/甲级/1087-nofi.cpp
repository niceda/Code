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

int e[201][201], weight[201], d[201], maxhappiness = -1;
map<string, int> cityId1;
map<int, string> cityId2;
bool visit[201];
vector<int> pre[201];
vector<int> temppath;
vector<int> path;

void DFS(int index) {
  temppath.push_back(index);
  if (pre[index].empty()) {
    int t = 0;
    for (int i = 0; i < temppath.size(); i++) {
      t += weight[temppath[i]];
    }
    if (t > maxhappiness) {
      path = temppath;
      maxhappiness = t;
    } else if (t == maxhappiness &&
               t / temppath.size() > maxhappiness / path.size()) {
      path = temppath;
    }
    temppath.pop_back();
    return;
  }

  for (int i = 0; i < pre[index].size(); i++) {
    DFS(pre[index][i]);
  }
  temppath.pop_back();
}

int main() {
  int n, k, t;
  string startcity, name;
  cin >> n >> k >> startcity;
  cityId1[startcity] = 0;
  cityId2[0] = startcity;
  weight[0] = 0;
  for (int i = 1; i <= n - 1; i++) {
    cin >> name >> t;
    cityId1[name] = i;
    cityId2[i] = name;
    weight[i] = t;
  }
  string name1, name2;
  int cost;
  fill(e[0], e[0] + 201 * 201, inf);
  for (int i = 0; i < k; i++) {
    cin >> name1 >> name2 >> cost;
    e[cityId1[name1]][cityId1[name2]] = cost;
    e[cityId1[name2]][cityId1[name1]] = cost;
  }

  fill(d, d + 201, inf);
  d[0] = 0;

  for (int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for (int j = 0; j < n; j++) {
      if (visit[j] == false && d[j] < minn) {
        u = j;
        minn = d[j];
      }
    }

    visit[u] = true;
    for (int v = 0; v < n; v++) {
      if (visit[v] == false && e[u][v] != inf) {
        if (d[u] + e[u][v] < d[v]) {
          pre[v].clear();
          pre[v].push_back(u);
          d[v] = d[u] + e[u][v];
        } else if (d[u] + e[u][v] == d[v]) {
          pre[v].push_back(u);
        }
      }
    }
  }

  DFS(cityId1["ROM"]);
  printf("%d %d %d %d\n", d[cityId1["ROM"]], d[cityId1["ROM"]], maxhappiness,
         maxhappiness / ((int)path.size() - 1));
  for (int i = path.size() - 1; i >= 0; i--) {
    if (i != path.size() - 1)
      cout << "->";
    cout << cityId2[path[i]];
  }
  return 0;
}
