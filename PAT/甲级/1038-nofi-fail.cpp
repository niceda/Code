#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

bool cmp(string a, string b) {
  int j = 0;
  while (a[j] == '0') {
    j++;
  }
  a = a.substr(j);
  j = 0;
  while (b[j] == '0') {
    j++;
  }
  b = b.substr(j);
  int len = max(a.length(), b.length());
  a.append(len - a.length(), a[0]);
  b.append(len - b.length(), b[0]);
  return a < b;
}

int main() {
  int n;
  cin >> n;
  vector<vector<string>> v(11);
  vector<vector<string>> zerov(8);
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    int j = 0;
    while (s[j] == '0') {
      j++;
    }
    if (j != 0) {
      zerov[j].push_back(s);
    } else {
      v[s[j] - '0'].push_back(s);
    }
  }

  for (int i = 1; i <= 10; i++) {
    sort(v[i].begin(), v[i].end(), cmp);
  }

  for (int i = 1; i <= 7; i++) {
    sort(zerov[i].begin(), zerov[i].end(), cmp);
  }

  string result;
  int flag = 0;
  string ss;
  for (int i = 7; i >= 1; i--) {
    for (int j = 0; j < zerov[i].size(); j++) {
      if (flag == 0) {
        ss = zerov[i][0];
        int count = 0;
        while (ss[count] == '0') {
          count++;
        }
        result += ss.substr(count);
        flag = 1;
      } else {
        result += zerov[i][j];
      }
      
    }
  }

  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      result += v[i][j];
    }
  }

  if (result.length() == 0) {
    cout << 0;
  } else {
    cout << result;
  }
  return 0;
}
