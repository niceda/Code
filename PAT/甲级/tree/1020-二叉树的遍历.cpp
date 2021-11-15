#include <iostream>
#include <queue>
using namespace std;
struct node {
  int data;
  node *lchild;
  node *rchild;
};
int post[31], in[31];
node *create(int postl, int postr, int inl, int inr) {
  if (postl > postr)
    return NULL;
  node *root = new node;
  root->data = post[postr];
  int k;
  for (k = inl; k <= inr; k++) {
    if (in[k] == post[postr])
      break;
  }
  int numLeft = k - inl;
  root->lchild = create(postl, postl + numLeft - 1, inl, k - 1);
  root->rchild = create(postl + numLeft, postr - 1, k + 1, inr);
  return root;
}

int flag = 0;
void BFS(node *root) {
  queue<node*> q;
  q.push(root);
  while(!q.empty()) {
    node *root = q.front(); 
    q.pop();
    if (flag != 0) cout << " ";
    flag = 1;
    cout << root->data;
    if (root->lchild != NULL) q.push(root->lchild);
    if (root->rchild != NULL) q.push(root->rchild);
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
