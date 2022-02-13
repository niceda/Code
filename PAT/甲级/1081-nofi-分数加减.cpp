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
  float result = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d/%d", &a, &b);
    result += (float)a / b;
  }
  cout << result;
  return 0;
}
