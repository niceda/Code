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
  string data;
  int lchild, rchild;
};

vector<node> v;
string DFS(int root) {
  string left;
  string right;
  if (v[root].lchild != -1) {
    left = DFS(v[root].lchild);
    if (v[v[root].lchild].lchild != -1 || v[v[root].lchild].rchild != -1) {
      left = '(' + left + ')';
    }
  }
  if (v[root].rchild != -1) {
    right = DFS(v[root].rchild);
    if (v[v[root].rchild].lchild != -1 || v[v[root].rchild].rchild != -1) {
      right = '(' + right + ')';
    }
  }
  string result =  left + v[root].data + right;
  return result;
}

int main() {
  int n, root;
  cin >> n;
  v.resize(n+1);
  vector<bool> flag(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i].data >> v[i].lchild >> v[i].rchild;
    if (v[i].lchild != -1) {
      flag[v[i].lchild] = 1;
    }
    if (v[i].rchild != -1) {
      flag[v[i].rchild] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (flag[i] == false) {
      root = i;
      break;
    }
  }
  string result = DFS(root);
  cout << result;
  return 0;
}
