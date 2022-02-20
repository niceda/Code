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
int post[31], in[31];

node *create(int inLeft, int inRight, int postLeft, int postRight) {
  if (postLeft > postRight) {
    return NULL;
  }
  node *root = new node;
  root->data = post[postRight];
  int i = inLeft;
  while(i <= inRight && in[i] != post[postRight]) i++;
  root->lchild = create(postLeft, postLeft + (i - inLeft) - 1, inLeft, i - 1);
  root->rchild = create(postLeft + (i - inLeft), postRight - 1, i + 1, inRight);
  return root;
};

bool flag = false;
void BFS(node *root) {
  queue<node *> q;
  q.push(root);
  while (!q.empty()) {
    node *t = q.front();
    q.pop();
    if (flag)
      cout << " ";
    cout << t->data;
    if (t->lchild != NULL) {
      q.push(t->lchild);
    }
    if (t->rchild != NULL) {
      q.push(t->rchild);
    }
    flag = true;
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> post[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> in[i];
  }
  node *root = create(0, n - 1, 0, n - 1);
  BFS(root);
  return 0;
}
