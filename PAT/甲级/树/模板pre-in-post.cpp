#include <iostream>
#include <vector>
using namespace std;

struct node {
  int data;
  node *lchild, *rchild;
};

vector<int> pre, in, post;

node* create1(int inLeft, int inRight, int preLeft, int preRight) {
  if (inLeft > inRight) {
    return NULL;
  }
  node *root = new node();
  root->data = pre[preLeft];
  int i = inLeft;
  while (i < inRight && pre[preLeft] != in[i]) i++;
  root->lchild = create1(inLeft, i - 1, preLeft + 1, preLeft + (i - inLeft));
  root->rchild = create1(i + 1, inRight, preLeft + (i - inLeft) + 1, preRight);
  return root;
}

node* create2(int inLeft, int inRight, int postLeft, int postRight) {
  if (inLeft > inRight) {
    return NULL;
  }
  node *root = new node();
  root->data = post[postRight];
  int i = inLeft;
  while (i < inRight && post[postRight] != in[i]) i++;
  root->lchild = create2(inLeft, i - 1, postLeft, postLeft + (i - inLeft) - 1);
  root->rchild = create2(i + 1, inRight, postLeft + (i - inLeft), postRight);
  return root;
}

int main() {
  int n;
  scanf("%d", &n);
  pre.resize(n), in.resize(n), post.resize(n);
  // 8
  // 7 2 3 4 6 5 1 8
  // 5 3 7 2 6 4 8 1
  for (int i = 0; i < n; i++) {
    cin >> in[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> pre[i];
  }
  // node *root = create1(0, n - 1, 0, n -1);
  // cout << root->data << endl;
  // cout << root->lchild->data << endl;
  // cout << root->rchild->data << endl;
  return 0;
}
