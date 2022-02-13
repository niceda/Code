#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

char c[5] = {'S', 'H', 'C', 'D', 'J' };

int main() {
  int n;
  cin >> n;
  int v[55], curr[55], temp[55];
  for (int i = 1; i < 55; i++) {
    cin >> v[i];
  }
  for (int i = 1; i < 55; i++) {
    curr[i] = i;
  }
  while (n-- != 0) {
    for (int i = 1; i < 55; i++) {
      temp[v[i]] = curr[i];
    }

    for (int i = 1; i < 55; i++) {
      curr[i] = temp[i];
    }
  }

  for (int i = 1; i < 55; i++) {
    if (i != 1) cout << " ";
    if (curr[i] >= 1 && curr[i] <= 13) {
      cout << c[0] << curr[i];
    } else if (curr[i] <= 26 && curr[i] > 13) {
      cout << c[1] << curr[i] - 13;
    } else if (curr[i] <= 39 && curr[i] > 26) {
      cout << c[2] << curr[i] - 26;
    } else if (curr[i] <= 52 && curr[i] > 39) {
      cout << c[3] << curr[i] - 39;
    } else {
      cout << c[4] << curr[i] - 52;
    }


  }
  return 0;
}
