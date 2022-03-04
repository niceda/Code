#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
int n, ismaxHeap = 1, isminHeap = 1;
vector<int> v;
vector<int> temppath;

void dfs(int index) {
  temppath.push_back(v[index]);
  if (2 * index + 1 >= n) {
    for (int i = 0; i < temppath.size(); i++) {
      if (i != 0) cout << " ";
      printf("%d", temppath[i]);
    }
    printf("\n");
    temppath.pop_back();
    return ;
  }
  if (isminHeap == 1) {
    if (v[2*index + 1] >= v[index]) {
    if (2 * index + 2 < n && v[2 * index + 2] < v[index]) {
      isminHeap = 0;
    }
    } else {
      isminHeap = 0;
    }
  }
  if (ismaxHeap == 1) {
    if (v[2*index + 1] <= v[index]) {
      if (2 * index + 2 < n && v[2 * index + 2] > v[index]) {
        ismaxHeap = 0;
      }
    } else {
      ismaxHeap = 0;
    }
  }
  if (2 * index + 2 < n) dfs(2 * index + 2);
  dfs(2 * index + 1);
  temppath.pop_back();
}

int main() {
  scanf("%d", &n);
  v.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  if (v[0] < v[1]) {
      if (2 < n) {
        if (v[0] < v[2]) {
          ismaxHeap = 0;
        }
      } else {
        ismaxHeap = 0;
      }
  } else {
    if (2 < n) {
      if (v[0] >= v[2]) {
        isminHeap = 0;
      }
    } else {
      isminHeap = 0;
    }
  }
  dfs(0);
  if (ismaxHeap != 1 && isminHeap != 1) {
    printf("Not Heap");
  } else if (ismaxHeap == 1) {
    printf("Max Heap");
  } else {
    printf("Min Heap");
  }
  return 0;
}