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

vector<node> v;
void BFS(int root) {
  int flag = 0;
  queue<int> q;
  q.push(root);
  while(!q.empty()) {
    int t = q.front();
    q.pop();
    if (flag != 0) cout << " ";
    cout << t;
    if (v[t].rchild != -1) {
      q.push(v[t].rchild);
    }
    if (v[t].lchild != -1) {
      q.push(v[t].lchild);
    }
    flag = 1;
  }

}

int flag = 0;
void inorder(int root) {
  if (root == -1) {
    return;
  }
  inorder(v[root].rchild);
  if (flag != 0) cout << " ";
  cout << root;
  flag = 1;
  inorder(v[root].lchild);
}

int main() {
  int n;
  cin >> n;
  v.resize(n);
  vector<bool> mark(n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '-') {
      v[i].lchild = -1;
    } else {
      v[i].lchild = c - '0';
      mark[c - '0'] = true;
    }
    cin >> c;
    if (c == '-') {
      v[i].rchild = -1;
    } else {
      v[i].rchild = c - '0';
      mark[c - '0'] = true;
    }
  }
  int root;
  for (int i = 0; i < n; i++) {
    if (mark[i] == false) {
      root = i;
      break;
    }
  }
  BFS(root);
  cout << endl;
  inorder(root);
  return 0;
}
