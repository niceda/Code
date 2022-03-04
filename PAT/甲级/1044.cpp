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
  vector<int> sum(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> sum[i];
    sum[i] += sum[i -1];
  }

  vector<string> result;
  int minn = 999999999;
  for (int i = 1; i <= n; i++) {
    int left = i;
    int right = n;
    while (left <= right) {
      int mid = (left + right) / 2;
      int t = sum[mid] - sum[i - 1];
      if (t >= m) {
        if (t < minn) {
          minn = t;
          string s;
          s += to_string(i);
          s += '-';
          s += to_string(mid);
          result.clear();
          result.push_back(s);
        } else if (t == minn) {
          string s;
          s += to_string(i);
          s += '-';
          s += to_string(mid);
          result.push_back(s);
          break;
        }
        right = mid - 1;
      } else if (t < m) {
        left = mid + 1;
      }
    }
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
  }
  return 0;
}
