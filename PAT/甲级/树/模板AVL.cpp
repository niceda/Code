#include <iostream>
#include <vector>
using namespace std;

struct node {
  int val;
  node *left, *right;
};

node* leftRotate(node *tree) {
  node *temp = tree->right;
  tree->right = temp->left;
  temp->left = tree;
  return temp;
}
node* rightRotate(node *tree) {
  node *temp = tree->left;
  tree->left = temp->right;
  temp->right = tree;
  return temp;
}
node* leftRightRotate(node *tree) {
  tree->left = leftRotate(tree->left);
  return rightRotate(tree);
} 
node* rightLeftRotate(node *tree) {
  tree->right = rightRotate(tree->right);
  return rightRotate(tree);
}
int getHeight(node *tree) {
  if (tree == NULL) return 0;
  int l = getHeight(tree->left);
  int r = getHeight(tree->right);
  return max(l, r) + 1;;
}
node *insert(node *tree, int val) {
  if (tree == NULL) {
    tree = new node();
    tree->val = val;
  } else if (tree->val > val) {
    tree->left = insert(tree->left, val);
    int l = getHeight(tree->left), r = getHeight(tree->right);
    if (l - r >= 2) {
      if (val < tree->left->val) {
        tree = rightRotate(tree);
      } else {
        tree = leftRightRotate(tree);
      }
    } 
  } else {
    tree->right = insert(tree->right, val);
    int l = getHeight(tree->left), r = getHeight(tree->right);
    if (r - l >= 2) {
      if (val > tree->right->val) {
        tree = leftRotate(tree);
      } else {
        tree = rightLeftRotate(tree);
      }
    }
  }
  return tree;
}


int main() {
  int n, temp;
  scanf("%d", &n);
  node *tree = NULL;
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    tree = insert(tree, temp);
  }
}
