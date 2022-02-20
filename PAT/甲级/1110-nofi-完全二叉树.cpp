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
  int lchild, rchild;
};

int main() {
  int n;
  cin >> n;
  vector<node> v(n);
  vector<bool> flag(n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '-') {
      v[i].lchild = -1;
    } else {
      v[i].lchild = c - '0';
      flag[c - '0'] = true;
    }
    cin >> c;
    if (c == '-') {
      v[i].rchild = -1;
    } else {
      v[i].rchild = c - '0';
      flag[c - '0'] = true;
    }
  }
  int root;
  for (int i = 0; i < n; i++) {
    if (flag[i] == false) {
      root = i;
      break;
    }
  }
  queue<int> q1;
  queue<int> q2;
  q1.push(root);
  int flagg = 1, flagg2 = 1, last;
  while (!q1.empty() || !q2.empty()) {
    if (q1.empty()) {
      swap(q1, q2);
    }
    int t = q1.front();
    last = t;
    q1.pop();
    if ((v[t].lchild == -1 && v[t].rchild != -1) ||
        (flagg2 == 0 && (v[t].lchild != -1 || v[t].rchild != -1))) {
      flagg = 0;
      break;
    }
    if (v[t].rchild == -1) {
      flagg2 = 0;
    }
    if (v[t].lchild != -1) {
      q2.push(v[t].lchild);
    }
    if (v[t].rchild != -1) {
      q2.push(v[t].rchild);
    }
  }
  if (flagg == 1) {
    cout << "YES"
         << " " << last;
  } else {
    cout << "NO"
         << " " << root;
  }
  return 0;
}
