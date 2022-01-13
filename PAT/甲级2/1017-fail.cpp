#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int t, p;
};

int cmp(Node a, Node b) { return (a.t < b.t); }

int main() {
  int n, k;
  cin >> n >> k;
  vector<Node> v;
  vector<int> w(3);
  int hh, mm, sec, p;
  for (int i = 0; i < n; i++) {
    scanf("%d:%d:%d %d", &hh, &mm, &sec, &p);
    if (hh >= 17 && (mm != 0 || sec != 0)) {
      continue;
    } else {
      v.push_back({(hh - 8) * 60 * 60 + mm * 60 + sec, p * 60});
    }
  }
  sort(v.begin(), v.end(), cmp);
  int total = 0, count = 0;
  for (int i = 0; i < v.size(); i++) {
    if (i < 3) {
      if (v[i].t < 0) {
        total -= v[i].t;
        w[i] = v[i].p;
        count++;
      } else {
        w[i] = v[i].t + v[i].p;
        count++;
      }
    } else {
      int wid, min = 100000000;
      for (int i = 0; i < 3; i++) {
        if (w[i] < min) {
          min = w[i];
          wid = i;
        }
      }
      // cout << min << "--------------------" << endl;
      if (min > 9 * 60 * 60) {
        continue;
      }
      if (v[i].t < min) {
        // cout << v[i].t << "--------------------" << endl;
        total += min - v[i].t;
        // cout << total << "--------------------" << endl;
      }
      w[wid] = v[i].p + min;
      count++;
      // cout << count << "------------------" << endl;
    }
  }
  printf("%.1f", (double)total / (60 * count));
  return 0;
}
