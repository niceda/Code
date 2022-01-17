#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

bool judge(string n) {
  for (int i = 0; i < n.length() - 1; i++) {
    if (n[i] != n[n.length() - 1 - i]) {
      return false;
    }
  }
  return true;
}

string dbs(string n) {
  string cn = n;
  reverse(cn.begin(), cn.end());
  string result;
  int carry = 0;
  for (int i = n.length() - 1; i >= 0; i--) {
    int t = (n[i] - '0'+ cn[i] - '0' + carry);
    result += t % 10 + '0';
    carry = t / 10;
  }
  if (carry != 0) {
    result += carry + '0';
  }
  reverse(result.begin(), result.end());
  return result;
}

int main() {
  int k;
  string n;
  cin >> n >> k;
  int cnt = 0;
  while (!judge(n) && cnt < k) {
    n = dbs(n);
    cnt++;
  }
  cout << n << endl;
  cout << cnt;
  return 0;
}
