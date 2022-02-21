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
int n, m, st, ed, mintime = inf, minsize = inf;
int e[510][510], tim[510][510], d[510], timed[510];
bool visit[510];
vector<int> pre1[510], pre2[510], temppath, path1, path2;

void dfs1(int v) {
  temppath.push_back(v);
  if (pre1[v].empty()) {
    int time = 0;
    for (int i = temppath.size() - 1; i >= 1; i--) {
      time += tim[temppath[i]][temppath[i-1]];
    }
    if (time < mintime) {
      path1 = temppath;
      mintime = time;
    }
    temppath.pop_back();
    return ;
  }
  for (int i = 0; i < pre1[v].size(); i++) {
    dfs1(pre1[v][i]);
  }
  temppath.pop_back();
}

void dfs2(int v) {
  temppath.push_back(v);
  if (pre2[v].empty()) {
    if (temppath.size() < minsize) {
      path2 = temppath;
      minsize = temppath.size();
    }
    temppath.pop_back();
    return ;
  }
  for (int i = 0; i < pre2[v].size(); i++) {
    dfs2(pre2[v][i]);
  }
  temppath.pop_back();
}

int main() {
  scanf("%d %d", &n, &m);
  fill(e[0], e[0] + 510 * 510, inf);
  fill(tim[0], tim[0] + 510 * 510, inf);
  for (int i = 0; i < m; i++) {
    int a, b, isOneWay, length, time;
    scanf("%d %d %d %d %d", &a, &b, &isOneWay, &length, &time);
    if (isOneWay == 1) {
      e[a][b] = length;
      tim[a][b] = time;
    } else if (isOneWay == 0) {
      e[a][b] = e[b][a] = length;
      tim[a][b] = tim[b][a] = time;
    }
  }
  scanf("%d %d", &st, &ed);
  fill(d, d + 510, inf);
  d[st] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for (int j = 0; j < n; j++) {
      if (visit[j] == false && d[j] < minn) {
        u = j;
        minn = d[j];
      }
    }
    if (u == -1) break;
    visit[u] = true;
    for (int v = 0; v < n; v++) {
      if (visit[v] == false && e[u][v] != inf) {
        if (e[u][v] + d[u] < d[v]) {
          d[v] = e[u][v] + d[u];
          pre1[v].clear();
          pre1[v].push_back(u);
        } else if (e[u][v] + d[u] == d[v]) {
          pre1[v].push_back(u);
        }
      }
    }
  }


  fill(visit, visit + 510, false);
  fill(timed, timed + 510, inf);
  timed[st] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for (int j = 0; j < n; j++) {
      if (visit[j] == false && timed[j] < minn) {
        u = j;
        minn = timed[j];
      }
    }
    if (u == -1) break;
    visit[u] = true;
    for (int v = 0; v < n; v++) {
      if (visit[v] == false && tim[u][v] != inf) {
        if (tim[u][v] + timed[u] < timed[v]) {
          timed[v] = tim[u][v] + timed[u];
          pre2[v].clear();
          pre2[v].push_back(u);
        } else if (tim[u][v] + timed[u] == timed[v]) {
          pre2[v].push_back(u);
        }
      }
    }
  }

  dfs1(ed);
  dfs2(ed);
  if (path1 != path2) {
    printf("Distance = %d: ", d[ed]);
    for (int i = path1.size() - 1; i >= 0; i--) {
      if (i != path1.size() - 1) cout << " -> ";
      cout << path1[i];
    }
    cout << endl;
    printf("Time = %d: ", timed[ed]);
    for (int i = path2.size() - 1; i >= 0; i--) {
      if (i != path2.size() - 1) cout << " -> ";
      cout << path2[i];
    }
  } else {
    printf("Distance = %d; Time = %d: ", d[ed], timed[ed]);
    for (int i = path2.size() - 1; i >= 0; i--) {
      if (i != path2.size() - 1) cout << " -> ";
      cout << path2[i];
    }
  }
  return 0;
}
