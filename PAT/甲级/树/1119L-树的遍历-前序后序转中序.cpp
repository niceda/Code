#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

vector<int> in, pre, post;
bool uniqu = true;
void getIn(int preLeft, int preRight, int postLeft, int postRight) {
  if (preLeft == preRight) {
    in.push_back(pre[preLeft]);
    return;
  }
  if (pre[preLeft] == post[postRight]) {
    int i = preLeft + 1;
    while(i < preRight && post[postRight-1] != pre[i]) i++;
    if (i - preLeft > 1) {
      getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
    } else {
      uniqu = false;
    }
    in.push_back(post[postRight]);
    getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  pre.resize(n), post.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &pre[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &post[i]);
  }
  getIn(0, n - 1, 0, n - 1);
  printf("%s\n%d", uniqu == true ? "Yes" :"No", in[0]);
  for (int i = 1; i < in.size(); i++) {
    printf(" %d", in[i]);
  }
  printf("\n");
  return 0;
}
