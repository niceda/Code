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

node *create(int postl, int postr, int inl, int inr) {
  if (postl > postr) {
    return NULL;
  }
  node *root = new node;
  root->data = post[postr];
  int k;
  for (k = inl; k <= inr; k++) {
    if (in[k] == root->data) {
      break;
    }
  }
  int numLeft = k - inl;
  root->lchild = create(postl, postl + numLeft - 1, inl, k - 1);
  root->rchild = create(postl + numLeft, postr - 1, k + 1, inr);
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
