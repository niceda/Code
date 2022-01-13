#include <iostream>
#include <vector>
using namespace std;

int e[501][501], weight[501], d[501], w[501], sp;
bool vis[501];
vector<vector<int>> path(501);
vector<int> mpath, temppath;
const int INF = 1000000000;

void dfs(int node, int ww) {
  temppath.push_back(node);
  if (path[node].empty()) {
    if (ww + weight[node] == w[sp]) {
      mpath = temppath;
      return ;
    }
  }
  for (int i = 0; i < path[node].size(); i++) {
    dfs(path[node][i], ww + weight[node]);
  }
  temppath.pop_back();
}

int main() {
  int capacity, n, m;
  int perfect;
  cin >> capacity >> n >> sp >> m;
  perfect = capacity / 2;
  for (int i = 1; i <= n; i++) {
    cin >> weight[i];
  }
  fill(e[0], e[0] + 501 * 501, INF);
  int a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    e[a][b] = e[b][a] = c;
  }

  fill(d, d + 501, INF);
  d[0] = 0;
  w[0] = 0;

  for (int i = 0; i < n + 1; i++) {
    int u = -1, minn = INF;
    for (int j = 0; j < n+1; j++) {
      if (vis[j] == false && d[j] < minn) {
        u = j;
        minn = d[j];
      }
    }

    if (u == -1) {
      break;
    }

    vis[u] = true;
    for (int v = 0; v < n+1; v++) {
      if (vis[v] == false && e[u][v] != INF) {
        if (d[u] + e[u][v] < d[v]) {
          path[v].clear();
          path[v].push_back(u);
          w[v] = w[u] + weight[v];
          d[v] = d[u] + e[u][v];
        } else if (d[u] + e[u][v] == d[v]) {
          if (w[u] + weight[v] > w[v]) {
            w[v] = w[u] + weight[v];
          }
          path[v].push_back(u);
        }
      }
    }
  }

  dfs(sp, 0);
  int send = 0, back = 0;
  if (mpath.size() > 0) {
    if (w[sp] < ((int)mpath.size() - 1) * perfect) {
      send = (mpath.size() - 1) * perfect - w[sp];
      back = 0;
    } else {
      back = w[sp] - (mpath.size() - 1) * perfect;
      send = 0;
    }
  }

  cout << send << " ";
  for (auto it = mpath.rbegin(); it != mpath.rend(); it++) {
    if (it != mpath.rbegin()) {
      cout << "->";
    }
    cout << *it;
  }

  cout << " " << back;
  return 0;
}
