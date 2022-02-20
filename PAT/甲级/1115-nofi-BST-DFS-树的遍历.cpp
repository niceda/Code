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

void insert(node *&root, int data) {
  if (root == NULL) {
    node *t = new node;
    t->data = data;
    t->lchild = NULL;
    t->rchild = NULL;
    root = t;
    return ;
  }
  if (data <= root->data) {
    insert(root->lchild, data);
  } else if (data > root->data) {
    insert(root->rchild, data);
  }
}

vector<int> result;

void BFS(node *root) {
  int flag = 0;
  queue<node*> q1;
  queue<node*> q2;
  q1.push(root);
  while(!q1.empty() || !q2.empty()) {
    if (q1.empty()) {
      swap(q1, q2);
      flag = 0;
    }
    if (flag == 0) {
      result.push_back(q1.size());
    }
    node *t = q1.front();
    q1.pop();
    if (t->lchild != NULL) {
      q2.push(t->lchild);
    }
    if (t->rchild != NULL) {
      q2.push(t->rchild);
    }
    flag = 1;
  }
}

int main() {
  int n, t;
  cin >> n;
  node *root = NULL;
  for (int i = 0; i < n; i++) {
    cin >> t;
    insert(root, t);
  }
  BFS(root);
  int n1, n2;
  if (result.size() >= 2) {
    n1 = result.back();
    n2 = result[result.size() - 2];
  } else {
    cout << 1;
    return 0;
  }
  printf("%d + %d = %d", n1, n2, n1 + n2);
  return 0;
}
