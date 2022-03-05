#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node {
  string institution;
  double tws;
  int ns;
  int b, a, t;
};

bool cmp(node a, node b) {
  return (int)a.tws != (int)b.tws
             ? a.tws > b.tws
             : (a.ns != b.ns ? a.ns < b.ns : a.institution < b.institution);
}

int main() {
  int n;
  cin >> n;
  string institution, id;
  int score, num = 0;
  map<string, int> m;
  vector<node> v;
  for (int i = 0; i < n; i++) {
    cin >> id >> score >> institution;
    for (int j = 0; j < institution.length(); j++) {
      institution[j] = tolower(institution[j]);
    }
    if (m.find(institution) == m.end()) {
      m[institution] = num++;
      v.push_back({institution});
    }
    v[m[institution]].ns++;
    if (id[0] == 'B') {
      v[m[institution]].b += score;
    } else if (id[0] == 'A') {
      v[m[institution]].a += score;
    } else if (id[0] == 'T') {
      v[m[institution]].t += score;
    }
  }
  for (int i = 0; i <v.size(); i++) {
    v[i].tws = v[i].b / 1.5 + v[i].a + v[i].t * 1.5;
  }
  sort(v.begin(), v.end(), cmp);
  cout << v.size() << endl;
  int rank = 0, pres = -1;
  for (int i = 0; i < v.size(); i++) {
    if (pres != (int)v[i].tws)
      rank = i + 1;
    pres = (int)v[i].tws;
    printf("%d ", rank);
    cout << v[i].institution;
    printf(" %d %d\n", (int)v[i].tws, v[i].ns);
  }
  return 0;
}

