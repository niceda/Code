#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node {
  string name;
  int gp, gmid, gfi, g;
};

struct grade {
  int gp, gmid, gfi;
};

bool cmp(node a, node b) { return a.g != b.g ? a.g > b.g : a.name < b.name; };

int main() {
  int p, m, n, t;
  cin >> p >> m >> n;
  string name;
  map<string, grade> mapp;
  for (int i = 0; i < p; i++) {
    cin >> name >> t;
    if (t >= 200)
      mapp[name].gp = t;
  }
  for (int i = 0; i < m; i++) {
    cin >> name >> t;
    if (mapp.find(name) != mapp.end())
      mapp[name].gmid = t;
  }
  for (int i = 0; i < n; i++) {
    cin >> name >> t;
    if (mapp.find(name) != mapp.end())
      mapp[name].gfi = t;
  }
  vector<node> v;
  for (auto u : mapp) {
    node temp;
    if (u.second.gmid > u.second.gfi)
      temp.g = (int)(u.second.gmid * 0.4 + u.second.gfi * 0.6 + 0.5);
    else
     temp.g = u.second.gfi;
    if (temp.g >= 60) {
      temp.name = u.first;
      temp.gp = u.second.gp;
      temp.gmid = u.second.gmid == 0 ? temp.gmid = -1 : u.second.gmid;
      temp.gfi = u.second.gfi;
      v.push_back(temp);
    }
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].name << " " << v[i].gp << " " << v[i].gmid << " " << v[i].gfi
         << " " << v[i].g << endl;
  }
  return 0;
}
