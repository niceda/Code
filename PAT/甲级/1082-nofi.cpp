#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

string num[10] = {"ling", "yi",  "er", "san", "si",
                  "wu",   "liu", "qi", "ba",  "jiu"};
string num2[4] = {"", " Shi", " Bai", " Qian"};

int main() {
  string s;
  cin >> s;
  if (s[0] == '-') {
    cout << "Fu ";
    s.erase(0, 1);
  }
  int zeroflag = 0;
  string result;
  reverse(s.begin(), s.end());
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == '0') {
      zeroflag = 1;
      if (i == 4) {
        result += " Wan";
      } else if (i == 8) {
        result += " Yi";
      }
      continue;
    } else if (s[i] != '0') {
      if (zeroflag == 1) {
        result += " ling";
        zeroflag = 0;
      }
      result += " " + num[s[i] - '0'];
      result += num2[i % 4];
      if (i == 4) {
        result += " Wan";
      } else if (i == 8) {
        result += " Yi";
      }
    }
  }
  result.erase(0, 1);
  cout << result;
  return 0;
}
