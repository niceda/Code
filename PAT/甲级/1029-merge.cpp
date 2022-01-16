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
  int n1, n2;
  cin >> n1;
  vector<long int> v1(n1);
  for (int i = 0; i < n1; i++) {
    cin >> v1[i];
  }
  cin >> n2;
  vector<long int> v2(n2);
  for (int i = 0; i < n2; i++) {
    cin >> v2[i];
  }
  vector<long int> result(n1 + n2);
  merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
  cout << result[(result.size() + 1) / 2 - 1];
  return 0;
}
