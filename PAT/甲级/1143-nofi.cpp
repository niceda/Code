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
    root = t;
    return;
  }
  if (data < root->data) {
    insert(root->lchild, data);
  } else if (data >= root->data) {
    insert(root->rchild, data);
  }
}

int find(node *root, int u, int v) {
  if (root->data == u) {
    return u;
  }
  if (root->data == v) {
    return v;
  }
  if ((root->data > u && root->data < v) || (root->data < u && root->data > v)) {
    return root->data;
  } else if (root->data > u && root->data > v) {
    return find(root->lchild, u, v);
  } else {
    return find(root->rchild, u, v);
  }
}

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  set<int> s;
  node *root = NULL;
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    s.insert(t);
    insert(root, t);
  }
  for (int i = 0; i < m; i++) {
    int u, v, findu = 1, findv = 1;
    scanf("%d %d", &u, &v);
    if (s.find(u) == s.end()) {
      findu = 0;
    }
    if (s.find(v) == s.end()) {
      findv = 0;
    }
    if (findu == 1 && findv == 1) {
      int ancestor = find(root, u, v);
      if (ancestor == u) {
        printf("%d is an ancestor of %d.\n", u, v);
      } else if (ancestor == v) {
        printf("%d is an ancestor of %d.\n", v, u);
      } else {
        printf("LCA of %d and %d is %d.\n", u, v, ancestor);
      }
    } else {
      if (findu == 0 && findv == 0) {
        printf("ERROR: %d and %d are not found.\n", u, v);
      } else if (findu == 0 && findv == 1) {
        printf("ERROR: %d is not found.\n", u);
      } else if (findu == 1 && findv == 0) {
        printf("ERROR: %d is not found.\n", v);
      }
    }
  }
  return 0;
}
