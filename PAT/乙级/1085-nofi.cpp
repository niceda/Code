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
  int score, num = 1, cnt = 0;
  map<string, int> m;
  vector<node> v(n + 1);
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
    v[m[xx]].jq +=
        id[0] == 'B' ? score / 1.5 : (id[0] == 'A' ? score : score * 1.5);
    v[m[xx]].cnt++;
  }
  sort(v.begin(), v.end(), cmp);
  cout << cnt << endl;
  int temp = 1;
  for (int i = 0; i < cnt; i++) {
    if (i == 0)
      printf("1 %s %d %d\n", v[i].xx.c_str(), (int)v[i].jq, v[i].cnt);
    else if (v[i].jq == v[i - 1].jq)
      printf("%d %s %d %d\n", temp, v[i].xx.c_str(), (int)v[i].jq, v[i].cnt);
    else {
      printf("%d %s %d %d\n", i+1, v[i].xx.c_str(), (int)v[i].jq, v[i].cnt);
      temp = i+1;
    }
  }
  return 0;
}
