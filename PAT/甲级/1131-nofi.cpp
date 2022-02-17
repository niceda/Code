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
  int line, index;
};

struct node2 {
  int line, index1, index2;
};

const int inf = 999999999;
vector<node> v[10000];

int start, destination;
vector<node2> result;
vector<int> temppath;

int flag[10000];
int cntstop = 999999999, cnttra = 999999999;
void DFS(int index, int flag[10000]) {
  temppath.push_back(index);
  flag[index] = 1;

  if (index == destination) {
    vector<node2> tempresult;
    int ttra = 0;
    int lastindex = temppath[0], lastline;
    for (int i = 0; i < v[temppath[0]].size(); i++) {
      if (v[temppath[0]][i].index == temppath[1]) {
        lastline = v[temppath[0]][i].line;
        break;
      }
    }
    for (int i = 2; i < temppath.size(); i++) {
      for (int j = 0; j < v[temppath[i - 1]].size(); j++) {
        if (v[temppath[i - 1]][j].index == temppath[i]) {
          if (v[temppath[i - 1]][j].line != lastline) {
            tempresult.push_back({lastline, lastindex, temppath[i]});
            lastindex = temppath[i];
            lastline = v[temppath[i - 1]][j].line;
            ttra++;
            break;
          }
        }
      }
    }
    if (tempresult.empty()) {
      tempresult.push_back({lastline, start, destination});
    } else if (tempresult.back().index2 != destination) {
      tempresult.push_back({lastline, tempresult.back().index2, destination});
    }
    if (temppath.size() < cntstop ||
        (temppath.size() == cntstop && ttra < cnttra)) {
      result = tempresult;
      cntstop = temppath.size();
      cnttra = ttra;
      for (int i = 0; i < temppath.size(); i++) {
        cout << temppath[i] << " ";
      }
      cout << endl;
    }
    temppath.pop_back();
    return;
  }

  for (int i = 0; i < v[index].size(); i++) {
    if (flag[v[index][i].index] == 0) {
      DFS(v[index][i].index, flag);
    }
  }
  temppath.pop_back();
}

bool cmp(vector<int> a, vector<int> b) { return true; }

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int k, t1, t2;
    cin >> k >> t1;
    for (int j = 1; j < k; j++) {
      cin >> t2;
      v[t1].push_back({i, t2});
      v[t2].push_back({i, t1});
    }
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> start >> destination;
    result.clear();
    temppath.clear();
    cntstop = 999999999, cnttra = 999999999;
    fill(flag, flag + 10000, 0);
    DFS(start, flag);
    cout << cntstop << endl;
    for (int i = 0; i < result.size(); i++) {
      printf("Take Line#%d from %d to %d.\n", result[i].line, result[i].index1,
             result[i].index2);
    }
  }
  return 0;
}
