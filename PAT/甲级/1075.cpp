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
  int id, perfectNum, problemScore[6], flag[7], total;
};

bool cmp(node a, node b) {
  return a.total != b.total
             ? a.total > b.total
             : (a.perfectNum != b.perfectNum ? a.perfectNum > b.perfectNum
                                             : a.id < b.id);
}

node v[100000];

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  int score[6];
  for (int i = 1; i <= k; i++) {
    cin >> score[i];
  }
  vector<node> v2;
  set<int> id;
  int a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    id.insert(a);
    v[a].id = a;
    if (c != v[a].problemScore[b] && c == score[b]) {
      v[a].problemScore[b] = c;
      v[a].perfectNum++;
      v[a].flag[6] = 1;
    } else if (c != -1 && c >= v[a].problemScore[b]) {
      v[a].problemScore[b] = c;
      v[a].flag[6] = 1;
    }
    v[a].flag[b] = 1;
  }
  for (auto i : id) {
    if (v[i].flag[6] == 1) {
      v2.push_back(v[i]);
    }
  }
  for (int i = 0; i < v2.size(); i++) {
    for (int j = 1; j <= k; j++) {
      v2[i].total += v2[i].problemScore[j];
    }
  }
  sort(v2.begin(), v2.end(), cmp);
  printf("1 %05d %d", v2[0].id, v2[0].total);
  for (int i = 1; i <= k; i++) {
    if (v2[0].flag[i] == 1) {
      cout << " " << v2[0].problemScore[i];
    } else {
      cout << " -";
    }
  }
  cout << endl;
  int rank = 1, lastScore = v2[0].total;
  for (int i = 1; i < v2.size(); i++) {
    if (v2[i].total == lastScore) {
      printf("%d %05d %d", rank, v2[i].id, v2[i].total);
    } else {
      printf("%d %05d %d", i + 1, v2[i].id, v2[i].total);
      rank = i + 1;
      lastScore = v2[i].total;
    }
    for (int j = 1; j <= k; j++) {
      if (v2[i].flag[j] == 1) {
        cout << " " << v2[i].problemScore[j];
      } else {
        cout << " -";
      }
    }
    cout << endl;
  }
  return 0;
}
