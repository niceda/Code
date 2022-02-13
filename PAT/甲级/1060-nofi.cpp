#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int n;
struct node {
  int factor, exponent;
};

node fun(string a) {
  if (a == "0") {
    return {0, 0};
  }
  if (a[0] == '0') {
    int e = 0, cnt = 2;
    while (a[cnt] == 0) {
      e--;
      cnt++;
    }
    // to see
    string t = a.substr(cnt, n);
    int factor = stoi(t);
    return {factor, e};
  } else {
    int flag = 0, cnt = 0, e = 0, factor;
    while (a[cnt] != '.' && cnt < a.size()) {
      cnt++;
      e++;
    }

    if (cnt < n) {
      a.erase(cnt, 1);
    }
    factor = stoi(a.substr(0, n));
    return {factor, e};
  }
}

int main() {
  string a, b;
  cin >> n >> a >> b;
  node aa = fun(a);
  node bb = fun(b);
  if (aa.factor == bb.factor && aa.exponent == bb.exponent) {
    cout << "YES";
    if (aa.factor == 0 && aa.exponent == 0) {
          cout << " " << 0;
    } else {
      printf(" 0.%d*10^%d", aa.factor, aa.exponent);
    }
  } else {
    cout << "NO";
    if (aa.factor == 0 && aa.exponent == 0) {
      cout << " " << 0;
    } else {
      printf(" 0.%d*10^%d", aa.factor, aa.exponent);
    }
    if (bb.factor == 0 && bb.exponent == 0) {
      cout << " " << 0;
    } else {
      printf(" 0.%d*10^%d", bb.factor, bb.exponent);
    }
  }
  return 0;
}
