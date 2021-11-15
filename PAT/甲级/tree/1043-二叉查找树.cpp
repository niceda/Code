#include <iostream>
#include <vector>
using namespace std;
struct node {
  int data;
  node *lchild;
  node *rchild;
};
vector<int> v;
void insert(node *&root, int data) {
  if (root == NULL) {
    root = new node;
    root->data = data;
    root->lchild = NULL;
    root->rchild = NULL;
    return;
  }
  if (data < root->data)
    insert(root->lchild, data);
  else
    insert(root->rchild, data);
}
void preorder(node *root, vector<int> &v) {
  if (root == NULL)
    return;
  v.push_back(root->data);
  preorder(root->lchild, v);
  preorder(root->rchild, v);
}
void Mirpreorder(node *root, vector<int> &v) {
  if (root == NULL)
    return;
  v.push_back(root->data);
  Mirpreorder(root->rchild, v);
  Mirpreorder(root->lchild, v);
}
void postorder(node *root, vector<int> &v) {
  if (root == NULL)
    return;
  postorder(root->lchild, v);
  postorder(root->rchild, v);
  v.push_back(root->data);
}
void Mirpostorder(node *root, vector<int> &v) {
  if (root == NULL)
    return;
  Mirpostorder(root->rchild, v);
  Mirpostorder(root->lchild, v);
  v.push_back(root->data);
}

int main() { 
  vector<int> origin, pre, post, mpre, mpost;
  int n, t;
  cin >> n;
  node *root = NULL;
  for (int i = 0; i < n; i++) {
    cin >> t;
    origin.push_back(t);
    insert(root, t);
  }
  preorder(root, pre);
  postorder(root, post);
  Mirpreorder(root, mpre);
  Mirpostorder(root, mpost);
  if (pre == origin) {
    cout << "YES" << endl;
    for (int i = 0; i < post.size(); i++) {
      if (i != 0) cout << " ";
      cout << post[i];
    }
  } else if (mpre == origin) {
    cout << "YES" << endl;
    for (int i = 0; i < mpost.size(); i++) {
      if (i != 0) cout << " ";
      cout << mpost[i];
    }
  } else 
    cout << "NO";
return 0; }
