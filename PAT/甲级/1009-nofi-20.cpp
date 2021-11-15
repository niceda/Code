#include <iostream>
#include <vector>
using namespace std;

struct node {
  int exp;
  double coe;
};

int main() {
  int k, n;
  double v[2001] = {0}, a;
  vector<node> v1;
  vector<node> v2;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> n >> a;
    v1.push_back(node{n, a});
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> n >> a;
    v2.push_back(node{n, a});
  }
  for (int i = 0; i < v2.size(); i++) {
    for (int j = 0; j < v1.size(); j++) {
      v[v1[i].exp + v2[j].exp] += v1[i].coe * v2[j].coe; 
    }
  }
  int cnt = 0;
  for (int i = 0; i < 2001; i++) {
    if (v[i] != 0)
      cnt++;
  }
  cout << cnt;
  for (int i = 2000; i >= 0; i--) {
    if (v[i] != 0)
      printf(" %d %.1lf", i, v[i]);
  }
  return 0;
}
