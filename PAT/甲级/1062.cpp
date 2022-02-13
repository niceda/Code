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
  int id, virtue, talent;
};

bool cmp(node a, node b) {
  if (a.virtue + a.talent > b.virtue + b.talent) {
    return true;
  } else if (a.virtue + a.talent == b.virtue + b.talent) {
    if (a.virtue > b.virtue) {
      return true;
    } else if (a.virtue < b.virtue) {
      return false;
    } else {
      return a.id < b.id;
    }
  } else {
    return false;
  }
}

int main() {
  int n, l, h, num = 0;
  cin >> n >> l >> h;
  vector<vector<node>> v(4);
  int id, vGrade, tGrade;
  for (int i = 0; i < n; i++) {
    cin >> id >> vGrade >> tGrade;
    if (vGrade >= l && tGrade >= l) {
      if (vGrade >= h && tGrade >= h) {
        v[0].push_back({id, vGrade, tGrade});
      } else if (vGrade >= h && tGrade < h) {
        v[1].push_back({id, vGrade, tGrade});
      } else if (vGrade < h && tGrade < h && vGrade >= tGrade) {
        v[2].push_back({id, vGrade, tGrade});
      } else {
        v[3].push_back({id, vGrade, tGrade});
      }
      num++;
    }
  }
  for (int i = 0; i < 4; i++) {
    sort(v[i].begin(), v[i].end(), cmp);
  }
  cout << num << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      cout << v[i][j].id << " " << v[i][j].virtue << " " << v[i][j].talent << endl;
    }
  }
  return 0;
}
