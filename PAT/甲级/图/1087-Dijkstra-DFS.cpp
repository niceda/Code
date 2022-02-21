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

int n, k, t, maxhappiness = -1, mincost = inf;
string startCity;
int e[201][201], weight[201], d[201];
bool visit[201];
vector<int> pre[201], path, temppath;
map<string, int> cityToInt;
map<int, string> intToCity;

int cntpath = 0;
void DFS(int index) {
  temppath.push_back(index);
  if (pre[index].empty() && intToCity[index] == startCity) {
    int happiness = 0;
    for (int i = 0; i < temppath.size(); i++) {
      happiness += weight[temppath[i]];
    }
    if (happiness > maxhappiness) {
      path = temppath;
      maxhappiness = happiness;
    } else if (happiness == maxhappiness &&
               happiness / temppath.size() > maxhappiness / path.size()) {
      path = temppath;
    }
    cntpath++;
    temppath.pop_back();
    return;
  }

  for (int i = 0; i < pre[index].size(); i++) {
    DFS(pre[index][i]);
  }
  temppath.pop_back();
}

int main() {
  cin >> n >> k >> startCity;
  cityToInt[startCity] = 0;
  intToCity[0] = startCity;
  weight[0] = 0;
  for (int i = 1; i <= n - 1; i++) {
    string name;
    cin >> name >> t;
    cityToInt[name] = i;
    intToCity[i] = name;
    weight[i] = t;
  }
  fill(e[0], e[0] + 201 * 201, inf);
  for (int i = 0; i < k; i++) {
    int cost;
    string name1, name2;
    cin >> name1 >> name2 >> cost;
    e[cityToInt[name1]][cityToInt[name2]] = cost;
    e[cityToInt[name2]][cityToInt[name1]] = cost;
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

  DFS(cityToInt["ROM"]);
  printf("%d %d %d %d\n", cntpath, d[cityToInt["ROM"]], maxhappiness,
         maxhappiness / ((int)path.size() - 1));
  for (int i = path.size() - 1; i >= 0; i--) {
    if (i != path.size() - 1)
      cout << "->";
    cout << intToCity[path[i]];
  }
  return 0;
}
