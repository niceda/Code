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
  int lchild, rchild;
};
int flag[35];

vector<node> result;
int flagg = 0;
void ordertravel(int root) {
  if (result[root].lchild != 0) {
    ordertravel(result[root].lchild);
  }
  if (flagg != 0)
    cout << " ";
  cout << root;
  flagg = 1;
  if (result[root].rchild != 0) {
    ordertravel(result[root].rchild);
  }
}

int main() {
  int n;
  cin >> n;
  result.resize(n + 1);
  vector<int> pre(n + 1);
  vector<int> post(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> pre[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> post[i];
  }
  int root = pre[1];
  flag[pre[1]] = 1;
  int isone = 1;
  for (int i = 2; i <= n; i++) {
    if (flag[pre[i]] == 0) {
      int t;
      for (int j = n; j >= 2; j--) {
        if (post[j] == pre[i - 1]) {
          t = post[j - 1];
          break;
        }
      }
      if (t != pre[i]) {
        result[pre[i - 1]].lchild = pre[i];
        result[pre[i - 1]].rchild = t;
        flag[pre[i]] = 1;
        flag[t] = 1;
      } else {
        result[pre[i - 1]].rchild = pre[i];
        flag[pre[i]] = 1;
        isone = 0;
      }
    }
  }
  if (isone == 1) {
    cout << "Yes" << endl;
  } else if (isone == 0) {
    cout << "No" << endl;
  }
  ordertravel(root);
  return 0;
}
