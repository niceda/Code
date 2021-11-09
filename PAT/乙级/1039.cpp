#include <iostream>
#include <map>
using namespace std;

int main() {
  char c1[128] = {0}, c2[128] = {0};
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < s1.length(); i++) {
    c1[s1[i]]++;
  }
  for (int i = 0; i < s2.length(); i++) {
    c2[s2[i]]++;
  }
  int cnt = 0, flag = 0;
  for (int i = 0; i < 128; i++) {
    if (c1[i] - c2[i] >= 0)
      continue;
    else {
      cnt += c2[i] - c1[i];
      flag = 1;
    }
  }
  if (flag == 0)
    cout << "Yes " << s1.length() - s2.length();
  else
    cout << "No " << cnt;
}
