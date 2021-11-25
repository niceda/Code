#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int e = 8 * 3600;
const int l = 17 * 3600;

struct node {
  int h, m, s, p;
};

bool cmp(node a, node b) {
  return a.h != b.h ? a.h < b.h : (a.m != b.m ? a.m < b.m : a.s < b.s);
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<node> v(n);
  vector<int> s;
  for (int i = 0; i < v.size(); i++) {
    scanf("%d:%d:%d %d", &v[i].h, &v[i].m, &v[i].s, &v[i].p);
  }
  sort(v.begin(), v.end(), cmp);
  int wait = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    int t = v[i].h * 3600 + v[i].m * 60 + v[i].s;
    if (t <= l) {
      if (s.size() < k) {
        if (t < e) {
          wait += e - t;
          s.push_back(e + v[i].p * 60);
        } else {
          s.push_back(t + v[i].p * 60);
        }
        sort(s.begin(), s.end());
        cnt++;
      } else {
        if (t < s[0]) {
          wait += s[0] - t;
          s[0] = s[0] + v[i].p * 60;
          sort(s.begin(), s.end());
          cnt++;
        } else {
          s[0] = t + v[i].p * 60;
          sort(s.begin(), s.end());
          cnt++;
        }
      }
    }
  }
  double a = (double)wait / (60 * cnt);
  printf("%.1lf", a);
  return 0;
}
