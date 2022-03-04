#include <iostream>
using namespace std;

int main() {
  string s;
  int n;
  cin >> s >> n;
  for (int i = 0; i < n -1; i++) {
    string temp;
    int cnt = 1;
    for (int j = 0; j < s.length(); j++) {
      char t;
      if (j == 0)
        t = s[0];
      else if (s[j] != t) {
        temp.push_back(t);
        temp.push_back(cnt + '0');
        t = s[j];
        cnt = 1;
      } else {
        cnt++;
      }
      if(j == s.length() - 1) {
        temp.push_back(t);
        temp.push_back(cnt+'0');
      }
    }
    s = temp;
  }
  cout << s;
  return 0;
}
