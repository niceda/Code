#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int minntime = 999999999;
struct node {
  int hour, minute, second, time, playTime, isVip;
};

int cmp1(node a, node b) { return a.time < b.time; };

bool cmp2(node a, node b) {
  if (a.time > minntime || b.time > minntime ||
      (a.isVip == 1 && b.isVip == 1) || (a.isVip != 1 && b.isVip != 1)) {
    return a.time < b.time;
  }
  if (a.isVip) {
    return true;
  }
  return false;
}

int main() {
  int n, k, m;
  cin >> n;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d:%d:%d %d %d", &v[i].hour, &v[i].minute, &v[i].second,
          &v[i].playTime, &v[i].isVip);
    v[i].time = v[i].hour * 60 * 60 + v[i].minute * 60 + v[i].second;
  }
  cin >> k >> m;
  vector<bool> table(k + 1);
  vector<int> tableServerSum(k + 1);
  vector<int> tableTime(k + 1, 8 * 60 * 60);
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    table[t] = true;
  }

  for (int i = 0; i < n; i++) {
    sort(v.begin() + i, v.end(), cmp1);
    int tableid;
    for (int j = 1; j < k + 1; j++) {
      if (tableTime[j] < minntime) {
        minntime = tableTime[j];
        tableid = j;
      }
      // else if (tableTime[j] == minntime && table[j] == true) {
      //   minntime = tableTime[j];
      //   tableid = j;
      // }
    }
    // cout << "tableid-----------" << tableid << endl;

    if (minntime <= v[i].time && v[i].time <= 21 * 60 * 60) {
      if (v[i].isVip == 1) {
        for (int j = 1; j < k + 1; j++) {
          if (tableTime[j] == minntime && table[j] == true) {
            minntime = tableTime[j];
            tableid = j;
          }
        }
      }
      int playTime = v[i].playTime * 60 > 7200 ? 120 : v[i].playTime;
      tableTime[tableid] = v[i].time + playTime * 60;
      printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", v[i].hour, v[i].minute,
             v[i].second, v[i].hour, v[i].minute, v[i].second, 0);
      tableServerSum[tableid]++;
    } else if (minntime > v[i].time && minntime <= 21 * 60 * 60 &&
               table[tableid] == true) {
      sort(v.begin() + i, v.end(), cmp2);
      int playTime = v[i].playTime * 60 > 7200 ? 120 : v[i].playTime;
      tableTime[tableid] = v[i].time + playTime * 60;
      tableTime[tableid] = minntime + playTime * 60;
      int wait = minntime - v[i].time;
      int hour = minntime / 3600, minute = (minntime / 60) % 60,
          second = minntime % 60;
      printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", v[i].hour, v[i].minute,
             v[i].second, hour, minute, second, (wait + 30) / 60);
      tableServerSum[tableid]++;
    } else if (minntime > v[i].time && minntime <= 21 * 60 * 60 &&
               table[tableid] == false) {
      int playTime = v[i].playTime * 60 > 7200 ? 120 : v[i].playTime;
      tableTime[tableid] = minntime + playTime * 60;
      int wait = minntime - v[i].time;
      int hour = minntime / 3600, minute = (minntime / 60) % 60,
          second = minntime % 60;
      printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", v[i].hour, v[i].minute,
             v[i].second, hour, minute, second, (wait + 30) / 60);
      tableServerSum[tableid]++;
    }
    minntime = 999999999;
  }
  for (int i = 1; i <= k; i++) {
    if (i != 1)
      cout << " ";
    cout << tableServerSum[i];
  }
  return 0;
}
