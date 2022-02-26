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
  int data, next;
};
node v[100010];

int main() {
  int head, n;
  set<int> removedata;
  vector<int> removelink;
  scanf("%d %d", &head, &n);
  for (int i = 0; i < n; i++) {
    int h, data, next;
    scanf("%d %d %d", &h, &data, &next);
    v[h].data = data;
    v[h].next = next;
  }
  int t = head, last = head;
  while (head != -1) {
    if (removedata.find(abs(v[head].data)) == removedata.end()) {
      removedata.insert(abs(v[head].data));
      last = head;
    } else {
      v[last].next = v[head].next;
      removelink.push_back(head);
    }
    head = v[head].next;
  }
  while (t != -1) {
    printf("%05d %d ", t, v[t].data);
    if (v[t].next != -1) {
      printf("%05d\n", v[t].next);
    } else {
      printf("-1\n");
    }
    t = v[t].next;
  }
  for (int i = 0; i < (int)removelink.size() - 1; i++) {
    printf("%05d %d %05d\n", removelink[i], v[removelink[i]].data,
           removelink[i + 1]);
  }
  if (!removelink.empty()) {
    printf("%05d %d -1", removelink.back(), v[removelink.back()].data);
  }
  return 0;
}
