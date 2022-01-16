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
  int group, score;
  string id;
};

struct node2 {
  int score, rank;
  string id;
};

bool cmp(node a, node b) {
  return a.score != b.score ? a.score > b.score : a.id < b.id;
}

bool cmp2(node2 a, node2 b) {
  return a.score != b.score ? a.score > b.score : a.id < b.id;
}

int main() {
  int n, k;
  cin >> n;
  vector<node> v;
  vector<vector<node2>> vg(n + 1);
  for (int i = 1; i <= n; i++) {
    int score;
    string id;
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> id >> score;
      v.push_back(node{i, score, id});
      vg[i].push_back(node2{score, 0, id});
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(vg[i].begin(), vg[i].end(), cmp2);
    int rank = 0, lastScore = -1;
    for (int j = 0; j < vg[i].size(); j++) {
      if (vg[i][j].score != lastScore) {
        rank = j + 1;
        lastScore = vg[i][j].score;
      }
      vg[i][j].rank = rank;
    }
  }
  sort(v.begin(), v.end(), cmp);
  cout << v.size() << endl;
  int finalRank = 0, lastScore = -1;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].score != lastScore) {
      finalRank = i + 1;
      lastScore = v[i].score;
    }
    for (int j = 0; j < vg[v[i].group].size(); j++) {
      if (v[i].id == vg[v[i].group][j].id) {
        cout << v[i].id << " " << finalRank << " " << v[i].group << " "
             << vg[v[i].group][j].rank << endl;
      }
    }
  }
  return 0;
}
