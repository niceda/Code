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
  node *lchild, *rchild;
};

vector<int> v;
node *construct(int left, int right) {
  if (left >= right) {
    return NULL;
  }
  node *root = new node;
  int n = right - left, cnt = 1;
  while (pow(2, cnt) - 1 <= n) {
    cnt++;
  }
  int rootPosition;
  if (cnt - 2 == 0) {
    rootPosition = right - 1;
  } else {
    rootPosition = right - pow(2, cnt - 2) + 1;
  }
  cout << left << " " << right << " " << rootPosition << endl;
  if (n - pow(2, cnt - 1) + 1 > pow(2, cnt - 1) / 2) {
    rootPosition -= n - pow(2, cnt - 1) + 1 - pow(2, cnt - 1) / 2;
  }
  root->data = v[rootPosition];
  root->lchild = construct(left, rootPosition);
  root->rchild = construct(rootPosition, right);
  return root;
}

int main() {
  int n;
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  node *root = construct(0, n);
  int flag = 0;
  queue<node *> q;
  q.push(root);
  while (!q.empty()) {
    node *root = q.front();
    q.pop();
    if (flag == 1)
      cout << " ";
    cout << root->data;
    if (root->lchild != NULL) {
      q.push(root->lchild);
    }
    if (root->rchild != NULL) {
      q.push(root->rchild);
    }
    flag = 1;
  }
  return 0;
}
