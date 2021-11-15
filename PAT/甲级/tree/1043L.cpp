#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, post;
int n, M = false;
void getpost(int root, int end) {
  if (root > end)
    return;
  int i = root + 1;
  int j = end;
  if (!M) {
    while (i <= end && pre[i] < pre[root])
      i++;
    while (j > root && pre[j] >= pre[root])
      j--;
  } else {
    while (i <= end && pre[i] >= pre[root])
      i++;
    while (j > root && pre[j] < pre[root])
      j--;
  }
  if (i - j - 1 != 0)
    return;
  getpost(root + 1, j);
  getpost(i, end);
  post.push_back(pre[root]);
}

int main() {
  cin >> n;
  pre.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> pre[i];
  }
  getpost(0, n - 1);
  if (post.size() != n) {
    post.clear();
    M = true;
    getpost(0, n - 1);
  }
  if (post.size() == n) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      if (i != 0)
        cout << " ";
      cout << post[i];
    }
  } else
    cout << "NO";
  return 0;
}
