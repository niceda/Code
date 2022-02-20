#include <iostream>
#include <vector>
using namespace std;

vector<int> pre, in;
int flag = 0;
void postorder(int preLeft, int preRight, int inLeft, int inRight) {
  if (preLeft > preRight || flag == 1) return;
  int i = inLeft;
  while(i < inRight && pre[preLeft] != in[i]) i++;
  postorder(preLeft + 1, preLeft + (i - inLeft), inLeft, i - 1);
  postorder(preLeft + (i - inLeft) + 1, preRight, i + 1, inRight);
  if (flag == 0) {
    printf("%d", in[i]);
    flag = 1;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  pre.resize(n);
  in.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &pre[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &in[i]);
  }
  postorder(0, n - 1, 0, n - 1);
  return 0;
}
