#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n1, m1, n2, m2, k, max = -1, min = 1001, t = 1, flag = 0;
  vector<int> v;
  scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
  for (int i = 2; i <= k; i++) {
    if (k % i == 0)
      v.push_back(i);
  }
  float a = (float)n1 / m1, b = (float)n2 / m2;
  while ((float)t / k <= std::min(a, b))
    t++;
  min = t;
  while ((float)t / k <= std::max(a, b))
    t++;
  max = t;
  for (int i = min; i <= max; i++) {
    int j = 0;
    for (; j < v.size(); j++) {
      if (i % v[j] == 0)
        break;
    }
    if (j == v.size()) {
      if (flag != 0)
        cout << " ";
      cout << i << "/" << k;
      flag = 1;
    }
  }
  return 0;
}
