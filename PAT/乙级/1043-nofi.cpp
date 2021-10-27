#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int c[6]{0};
  for (int i = 0; i < s.length(); i++) {
    if(s[i] == 'P')
      c[0]++;
    if(s[i] == 'A')
      c[1]++;
    if(s[i] == 'T')
      c[2]++;
    if(s[i] == 'e')
      c[3]++;
    if(s[i] == 's')
      c[4]++;
    if(s[i] == 't')
      c[5]++;
  }
  int max = -1;
  for (int i = 0; i < 5; i++) {
    if(max < c[i])
      max = c[i];
  }
  for (int i = 0; i < max; i++) {
    if(c[0] > 0) {
      cout << 'P';
      c[0]--;
    }
    if(c[1] > 0) {
      cout << 'A';
      c[1]--;
    }
    if(c[2] > 0) {
      cout << 'T';
      c[2]--;
    }
    if(c[3] > 0) {
      cout << 'e';
      c[3]--;
    }
    if(c[4] > 0) {
      cout << 's';
      c[4]--;
    }
    if(c[5] > 0) {
      cout << 't';
      c[5]--;
    }
  }
  return 0;
}
