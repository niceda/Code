#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node {
  int d, h, m;
  string state;
};

bool cmp(node a, node b) {
  return a.d != b.d ? a.d < b.d : (a.h != b.h ? a.h < b.h : a.m < b.m);
}

int main() {
  int n, M, d, h, m;
  int charge[24];
  string name, state;
  map<string, vector<node>> mm;
  for (int i = 0; i < 24; i++) {
    cin >> charge[i];
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> name;
    scanf("%d:%d:%d:%d", &M, &d, &h, &m);
    cin >> state;
    mm[name].push_back({d, h, m, state});
  }
  for (auto &it : mm) {
    cout << it.first << " ";
    printf("%02d\n", M);
    sort(it.second.begin(), it.second.end(), cmp);
    int flag = 0, total = 0, od, oh, om;
    for (int i = 0; i < it.second.size(); i++) {
      if (it.second[i].state == "on-line") {
        od = it.second[i].d;
        oh = it.second[i].h;
        om = it.second[i].m;
        flag = 1;
        continue;
      }
      if (flag == 1 && it.second[i].state == "off-line") {
        int tmoney = 0, tmn = 0;
        if (it.second[i].d > od || it.second[i].h > oh) {
          tmn = (60 - om) + it.second[i].m;
          tmoney +=
              charge[oh] * (60 - om) + charge[it.second[i].h] * it.second[i].m;
        } else {
          tmn = it.second[i].m - om;
          tmoney = charge[oh] * tmn;
        }
        for (int j = od * 24 + oh + 1; j < it.second[i].d * 24 + it.second[i].h;
             j++) {
          tmn += 60;
          tmoney += charge[j % 24] * 60;
        }
        total += tmoney;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", od, oh, om,
               it.second[i].d, it.second[i].h, it.second[i].m, tmn,
               (double)tmoney / 100);
        flag = 0;
      }
    }
    printf("Total amount: $%.2lf\n", (double)total / 100);
  }
  return 0;
}
