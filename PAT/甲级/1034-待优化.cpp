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
  string head;
  int num;
};

bool cmp(node a, node b) { return a.head < b.head; }

int minn = 99999, totaltime = 0, totalcalltimeperson = 0, totalperson = 0;
string head;
map<string, map<string, int>> v;
map<string, bool> vis;
map<string, map<string, bool>> vis2;
void dfs(string name) {
  if (vis[name] == true) {
    return;
  }
  vis[name] = true;
  totalperson++;
  int t = 0;
  for (auto it = v[name].begin(); it != v[name].end(); it++) {
    if (vis2[name][it->first] == false) {
      totaltime += it->second;
      vis2[name][it->first] = true;
      vis2[it->first][name] = true;
    }
    t += it->second;
  }
  if (totalcalltimeperson < t) {
    totalcalltimeperson = t;
    head = name;
  }
  for (auto it = v[name].begin(); it != v[name].end(); it++) {
    dfs(it->first);
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  string a, b;
  int c;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    v[a][b] += c;
    v[b][a] += c;
    vis[a] = false;
    vis[b] = false;
    vis2[a][b] = false;
    vis2[b][a] = false;
  }

  vector<node> h;
  for (auto it = v.begin(); it != v.end(); it++) {
    if (vis[it->first] == false) {
      // cout << "enter" << endl;
      dfs(it->first);
      // cout << totaltime << " " << totalperson << endl;
      if (totaltime > k && totalperson > 2) {
        h.push_back(node{head, totalperson});
      }
      totalcalltimeperson = 0;
      totalperson = 0;
      totaltime= 0;
    }
  }
  sort(h.begin(), h.end(), cmp);
  cout << h.size() << endl;
  for (int i = 0; i < h.size(); i++) {
    cout << h[i].head << " " << h[i].num << endl;
  }
  return 0;
}
