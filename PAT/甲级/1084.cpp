#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

bool suppose[127];
bool actually[127];
bool flag[127];

int main() {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  for (int i = 0; i < s2.length(); i++) {
    actually[toupper(s2[i])] = true;
  }
  for (int i = 0; i < s1.length(); i++) {
    if (actually[toupper(s1[i])] == false && flag[toupper(s1[i])] == false) {
        char t = toupper(s1[i]);
        cout << t;
        flag[toupper(s1[i])] = true;
    }
  }
  return 0;
}
