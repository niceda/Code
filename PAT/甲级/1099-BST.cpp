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
  int data;
  int lchild, rchild;
};

vector<int> position;
vector<node> v;
vector<int> key;
void calpos(int index) {
  if (index == -1) {
    return;
  }
  queue<int> q;
  if (v[index].lchild != -1) {
    q.push(v[index].lchild);
  }
  int cnt = 0;
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    if (v[t].lchild != -1) {
      q.push(v[t].lchild);
    }
    if (v[t].rchild != -1) {
      q.push(v[t].rchild);
    }
    cnt++;
  }
  position[index] = cnt;
  calpos(v[index].lchild);
  calpos(v[index].rchild);
}

void insert(int l, int root) {
  if (root == -1) {
    return;
  }
  v[root].data = key[l + position[root]];
  insert(l, v[root].lchild);
  insert(l + position[root] + 1, v[root].rchild);
}

int flag = 0;
void BFS(int root) {
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    if (flag != 0)
      cout << " ";
    cout << v[t].data;
    if (v[t].lchild != -1) {
      q.push(v[t].lchild);
    }
    if (v[t].rchild != -1) {
      q.push(v[t].rchild);
    }
    flag = 1;
  }
}

int main() {
  int n;
  cin >> n;
  v.resize(n);
  key.resize(n);
  position.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].lchild >> v[i].rchild;
  }
  for (int i = 0; i < n; i++) {
    cin >> key[i];
  }
  sort(key.begin(), key.end());
  calpos(0);
  insert(0, 0);
  BFS(0);
  return 0;
}
