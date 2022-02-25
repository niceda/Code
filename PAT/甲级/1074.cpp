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
  int data, address, next;
};

node v[100000];

int main() {
  int head, n, k, address;
  cin >> head >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> address;
    v[address].address = address;
    cin >> v[address].data >> v[address].next;
  }
  vector<node> v2;
  for (int i = 0; i < n && head != -1; i++) {
    v2.push_back({v[head].data, v[head].address, v[head].next});
    head = v[head].next;
  }
  if (k <= v2.size()) {
    for (int i = 0; i + k <= v2.size(); i += k) {
      reverse(v2.begin() + i, v2.begin() + i + k);
    }
  }
  for (int i = 0; i < v2.size() - 1; i++) {
    printf("%05d %d %05d\n", v2[i].address, v2[i].data, v2[i + 1].address);
  }
  printf("%05d %d %d", v2[v2.size() - 1].address, v2[v2.size() - 1].data, -1);
  return 0;
}
