#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct node {
  float kucun, price;
};

int cmp(node a, node b) { return a.price * b.kucun > a.kucun * b.price; }

int main() {
  int n, N;
  cin >> n >> N;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].kucun;
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i].price;
  }
  sort(v.begin(), v.end(), cmp);
  float total = 0.0;
  for (int i = 0; i < n; i++) {
    if (v[i].kucun <= N) {
      total += v[i].price;
    } else {
      total += v[i].price * (N / v[i].kucun);
      break;
    }
    N = N - v[i].kucun;
  }
  printf("%.2f", total);
  return 0;
}
