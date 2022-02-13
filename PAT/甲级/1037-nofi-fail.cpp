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
  vector<long long> coupons, product;
  long long t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    coupons.push_back(t);
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    product.push_back(t);
  }
  sort(coupons.begin(), coupons.end(), greater<int>());
  sort(product.begin(), product.end(), greater<int>());
  int indexMax = 0, indexMin = (int)product.size() - 1;
  long long total = 0;
  for (int i = 0; i < coupons.size(); i++) {
    if (indexMax >= (int)product.size() || indexMin < 0) {
      break;
    }
    if (coupons[i] > 0 && product[indexMax] > 0) {
      total += coupons[i] * product[indexMax];
      indexMax++;
    } else if (coupons[i] < 0 && product[indexMin] < 0) {
      total += coupons[i] * product[indexMin];
      indexMin--;
    }
  }
  cout << total;
  return 0;
}
