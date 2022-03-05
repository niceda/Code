#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int n, t, k;
  string s;
  scanf("%d %d %d", &n, &t, &k);
  for (int i = 0; i < k; i++) {
    char last;
    int score = 0;
    vector<char> same, consecutive;
    cin >> s;
    last = s[0];
    same.push_back(s[0]);
    consecutive.push_back(s[0]);
    if (s[0] == 'f') score -= 2;  
    if (s.back() == 'a') score -= 1;
    for (int i = 1; i < s.length(); i++) {
      if (s[i-1] == 'a' && (s[i] == 'e' || s[i] == 'h'))
        score -= 4;
      if (last == s[i]) {
        same.push_back(s[i]);
      } else {
        if (same.size() > 5)
          score += 3;
        same.clear();
        same.push_back(s[i]);
        last = s[i];
      }
      if (s[i-1] + 1 == s[i]) {
        consecutive.push_back(s[i]);
      } else {
        if (consecutive.size() > 3) {
          score += 5;
        }
        consecutive.clear();
        consecutive.push_back(s[i]);
      }
    }
    if (same.size() > 5)
      score += 3;
    if (consecutive.size() > 3)
      score += 5;
    if (score > t)
      printf("%d!!!\n", score);
    else
      printf("%d\n", score);
  }
  return 0;
}