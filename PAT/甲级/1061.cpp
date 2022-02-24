#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
  string s1, s2, s3, s4;
  cin >> s1 >> s2 >> s3 >> s4;
  int flag = 0;
  for (int i = 0, j = 0; i < s1.length() && j < s2.length(); i++, j++) {
    if (isupper(s1[i]) && s1[i] == s2[j]) {
      if (flag == 0 && s1[i] >= 'A' && s1[i] <= 'G') {
        cout << week[s1[i] - 'A'];
        flag = 1;
      } else if (flag == 1 && s1[i] >= 'A' && s1[i] <= 'N') {
        cout << " " << s1[i] - 'A' + 10;
        break;
      }
    }
    if (flag == 1 && isdigit(s1[i]) && s1[i] == s2[j]) {
      cout << " 0" << s1[i] - '0';
      break;
    }
  }
  cout << ":";
  for (int i = 0, j = 0; i < s3.length() && j < s4.length(); i++, j++) {
    if (isalpha(s3[i]) && s3[i] == s4[j]) {
      printf("%02d", i);
    }
  }
  return 0;
}
