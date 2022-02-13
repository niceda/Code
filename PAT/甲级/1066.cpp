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
  int v, height;
  node *lchild;
  node *rchild;
};

node *newNode(int v) {
  node *Node = new node;
  Node->v = v;
  Node->height = 1;
  Node->lchild = Node->rchild = NULL;
  return Node;
}
int getHeight(node *root) {
  if (root == NULL) {
    return 0;
  }
  return root->height;
}
int getBalanceFator(node *root) {
  return getHeight(root->lchild) - getHeight(root->rchild);
}
void updateHeight(node *root) {
  root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
void L(node *&root) {
  node *temp = root->rchild;
  root->rchild = temp->lchild;
  temp->lchild = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
}
void R(node *&root) {
  node *temp = root->lchild;
  root->lchild = temp->rchild;
  temp->rchild = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
}
void insert(node *&root, int val) {
  if (root == NULL) {
    root = newNode(val);
    return ;
  }
  if (val < root->v) {
    insert(root->lchild,val);
    updateHeight(root);
    if (getBalanceFator(root) == 2) {
      if (getBalanceFator(root->lchild) == 1) {
        R(root);
      } else if (getBalanceFator(root->lchild) == -1) {
        L(root->lchild);
        R(root);
      }
    } 
  } else if (val >= root->v) {
    insert(root->rchild, val);
    updateHeight(root);
    if (getBalanceFator(root) == -2) {
      if (getBalanceFator(root->rchild) == -1) {
        L(root);
      } else if (getBalanceFator(root->rchild) == 1) {
        R(root->rchild);
        L(root);
      }
    }
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
  cout << root->v;
  return 0;
}
