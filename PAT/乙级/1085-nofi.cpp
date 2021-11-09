#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node {
  string xx;
  double jq;
  int cnt;
};

bool cmp(node a, node b) {
  return a.jq != b.jq ? a.jq > b.jq
                      : (a.cnt != b.cnt ? a.cnt < b.cnt : a.xx < b.xx);
}

int main() {
  int n;
  cin >> n;
  string xx, id;
  int score, num = 0, cnt = 0;
  map<string, int> m;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    cin >> id >> score >> xx;
    for (int j = 0; j < xx.length(); j++) {
      xx[j] = tolower(xx[j]);
    }
    if (m.find(xx) == m.end()) {
      m[xx] = num++;
      v[m[xx]].xx = xx;
      cnt++;
    }
    v[m[xx]].cnt++;
    v[m[xx]].jq +=
        id[0] == 'B' ? score / 1.5 : (id[0] == 'A' ? score : score * 1.5);
  }
  sort(v.begin(), v.end(), cmp);
  cout << cnt << endl;
  int rank = 0, pres = -1;
  for (int i = 0; i < cnt; i++) {
    if (pres != (int)v[i].jq) rank = i + 1;
    pres = (int)v[i].jq;
    printf("%d ", rank);
    cout << v[i].xx;
    printf(" %d %d\n", (int)v[i].jq, v[i].cnt);
  }
  return 0;
}
