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
  int n;
  cin >> n;
  int t;
  vector<int> position(n);
  for (int i = 0; i < n; i++) {
    cin >> t;
    position[t] = i;
  }
  int cnt = 0, flag = 0;
  while (flag == 0) {
    if (position[0] != 0) {
      int temp = position[0];
      // cout << temp << "postion" << endl;
      position[0] = position[position[0]];
      position[temp] = temp;
      cnt++;
    } else {
      int flag2 = 0;
      for (int i = 1; i < n; i++) {
        if (position[i] != i) {
          int temp = position[i];
          position[i] = 0;
          position[0] = temp;
          cnt++;
          flag2 = 1;
          break;
        }
        if (flag2 == 0) {
          flag = 1;
        }
      }
    }
  }
  cout << cnt;
  return 0;
}
