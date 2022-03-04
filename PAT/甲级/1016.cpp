#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct record {
  int dd, hh, mm;
  string stat;
};

int cmp(record a, record b) {
  return (a.dd < b.dd || a.hh < b.hh || a.mm < b.mm);
}

int main() {
  int n, sum = 0;
  int toll[24];
  for (int i = 0; i < 24; i++) {
    cin >> toll[i];
  }
  for (int i = 0; i < 24; i++) {
    sum += 60 * toll[i];
  }
  map<string, vector<record>> m;
  string name, stat;
  int t, dd, hh, mm;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> name;
    scanf("%d:%d:%d:%d", &t, &dd, &hh, &mm);
    cin >> stat;
    m[name].push_back({dd, hh, mm, stat});
  }
  for (auto var : m) {
    sort(var.second.begin(), var.second.end(), cmp);
    cout << var.first;
    printf(" %02d\n", t);
    int total = 0, dd, hh, mm;
    bool flag = false;
    for (auto it = var.second.begin(); it != var.second.end(); it++) {
      if (flag == false && it->stat == "on-line") {
        dd = it->dd;
        hh = it->hh;
        mm = it->mm;
        flag = true;
      }
      if (flag == true && it->stat == "off-line") {
        int t = 0, tm = 0;
        if (dd == it->dd && hh == it->hh) {
          t = toll[hh] * (it->mm - mm);
          printf("%02d:%02d:%02d: %02d:%02d:%02d: %d $%.2f\n", dd, hh, mm,
                 it->dd, it->hh, it->mm, t, (double)t / 100);
        } else {
          tm = (60 - mm) + it->mm + (it->dd - dd) * 60 * 24 +
               (it->hh - hh - 1) * 60;
          t = toll[hh] * (60 - mm) + toll[it->hh] * (it->mm);
          // cout << hh << "---" << (60 - mm)  << "---" << t << "--------------------stat" << endl;
          t += (it->dd - dd) * sum;
          if (hh + 1 < it->hh) {
            for (int i = hh + 1; i < it->hh; i++) {
              t += toll[i] * 60;
            }
          } else {
            for (int i = it->hh; i < hh + 1; i++) {
              t -= toll[i] * 60;
            }
          }
          // cout << t << "--------------------end" << endl;
          printf("%02d:%02d:%02d: %02d:%02d:%02d: %d $%.2f\n", dd, hh, mm,
                 it->dd, it->hh, it->mm, tm, t / 100.0);
        }
        total += t;
        flag = false;
      }
    }
    if (total == 0) {
      printf("Total amount: $0");
    }
    printf("Total amount: $%.2f\n", total / 100.0);
  }
  return 0;
}
