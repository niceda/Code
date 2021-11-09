#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node {
  string name;
  int gp, gmid, gfi, g;
};

bool cmp(node a, node b) { return a.g != b.g ? a.g > b.g : a.name < b.name; };

int main() {
  int p, m, n, score;
  cin >> p >> m >> n;
  string name;
  map<string, int> ma;
  vector<node> v(p);
  for (int i = 0; i < p; i++) {
    cin >> name >> score;
    if (score >= 200) {
      ma[name] = i;
      v[ma[name]].name = name;
      v[ma[name]].gp = score;
      v[ma[name]].gmid = -1;
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> name >> score;
    if (ma.find(name) != ma.end())
      v[ma[name]].gmid = score;
  }
  for (int i = 0; i < n; i++) {
    cin >> name >> score;
    if (ma.find(name) != ma.end())
      v[ma[name]].gfi = score;
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i].gmid > v[i].gfi)
      v[i].g = (int)(v[i].gmid * 0.4 + v[i].gfi * 0.6 + 0.5);
    else
      v[i].g = v[i].gfi;
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) {
    if(v[i].g >= 60)
    cout << v[i].name << " " << v[i].gp << " " << v[i].gmid << " " << v[i].gfi
         << " " << v[i].g << endl;
  }
  return 0;
}
