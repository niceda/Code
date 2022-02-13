#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int n, total = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    total += v[i];
  }
  sort(v.begin(), v.end());
  int mid = n / 2;
  int min = n - mid - mid, sum = 0;
  for (int i = 0; i < mid; i++) {
    sum += v[i];
  }
  int max = total - 2 * sum;
  cout << min << " " << max;
  return 0;
}
