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
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n - 1; i++) {
    if (v[i] <= m / 2) {
      int left = i + 1;
      int right = n - 1;
      while (left <= right) {
        int mid = (left + right) / 2;
        if (v[i] + v[mid] == m) {
          cout << v[i] << " " << v[mid];
          return 0;
        } else if (v[i] + v[mid] > m) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
    }
  }
  cout << "No Solution";
  return 0;
}
