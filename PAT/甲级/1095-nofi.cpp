#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

struct node {
  string id, status;
  int time;
};

bool cmp(node a, node b) { return a.time < b.time; }

int main() {
  int n, k;
  cin >> n >> k;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].id;
    int hour, minute, second;
    scanf("%d:%d:%d", &hour, &minute, &second);
    v[i].time = hour * 3600 + minute * 60 + second;
    cin >> v[i].status;
  }
  sort(v.begin(), v.end(), cmp);
  map<string, vector<int>> mm;
  for (int i = 0; i < n; i++) {
    if (mm[v[i].id].empty() && v[i].status == "in") {
      mm[v[i].id].push_back(i);
    } else if (!mm[v[i].id].empty() && v[mm[v[i].id].back()].status == "in" &&
               v[i].status == "in") {
      mm[v[i].id].back() = i;
    } else if (!mm[v[i].id].empty() && v[mm[v[i].id].back()].status == "in" &&
               v[i].status == "out") {
      mm[v[i].id].push_back(i);
    } else if (!mm[v[i].id].empty() && v[mm[v[i].id].back()].status == "out" &&
               v[i].status == "in") {
      mm[v[i].id].push_back(i);
    }
  }
  for (int i = 0; i < k; i++) {
    int hour, minute, second, cnt = 0;
    scanf("%d:%d:%d", &hour, &minute, &second);
    int time = hour * 3600 + minute * 60 + second;
    for (auto val : mm) {
      for (int j = 0; j < val.second.size() && time >= v[val.second[j]].time;
           j += 2) {
        if (time < v[val.second[j + 1]].time) {
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }

  int maxtime = -1;
  set<string> result;
  for (auto val : mm) {
    int t = 0;
    for (int j = 0; j < val.second.size(); j += 2) {
      t += v[val.second[j + 1]].time - v[val.second[j]].time;
    }
    if (t > maxtime) {
      maxtime = t;
      result.clear();
      result.insert(val.first);
    } else if (t == maxtime) {
      result.insert(val.first);
    }
  }
  for (auto val : result) {
    cout << val << " ";
  }
  printf("%02d:%02d:%02d", maxtime / 3600, (maxtime / 60) % 60, maxtime % 60); 
  return 0;
}
