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
  int address, key;
};

bool cmp(node a, node b) { return a.key < b.key; }

int main() {
  int n, address, next;
  cin >> n >> address;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].address >> v[i].key >> next;
  }
  sort(v.begin(), v.end(), cmp);
  cout << n << " " << v[0].address << endl;
  for (int i = 0; i < n - 1; i++) {
    printf("%05d %d %05d\n", v[i].address, v[i].key, v[i + 1].address);
  }
  printf("%05d %d %d", v[n - 1].address, v[n - 1].key, -1);
  return 0;
}
