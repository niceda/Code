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

int flag = 0;
void postordertrave(node *root) {
  if (root == NULL) {
    return ;
  }
  postordertrave(root->lchild);
  postordertrave(root->rchild);
  if (flag != 0) cout << " ";
  cout << root->data;
  flag = 1;
}

int main() {
  int n;
  cin >> n;
  string s;
  int t;
  cin >> s >> t;
  node *root = new node;
  root->data = t;
  string lastoperate = "Push";
  node *lastnode = root;
  stack<node*> sta;
  sta.push(root);
  for (int i = 1; i < 2 * n; i++) {
    cin >> s;
    if (s == "Push") {
      cin >> t;
      node *tn = new node;
      tn->data = t;
      if (lastoperate == "Push") {
        lastnode->lchild = tn; 
      } else if (lastoperate == "Pop") {
        lastnode->rchild = tn;
      }
      sta.push(tn);
      lastnode = tn;
      lastoperate = "Push";
    } else if (s == "Pop") {
      lastoperate = "Pop";
      lastnode = sta.top();
      sta.pop();
    }
  }
  postordertrave(root);
  return 0;
}
