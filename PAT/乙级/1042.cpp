#include <iostream>
using namespace std;

int main() {
  int c[256]{0};
  string s;
  getline(cin, s);
  for (int i = 0; i < s.length(); i++) {
    c[s[i]]++;
  }
  char a;
  int max = -1;
  for (int i = 'a'; i <= 'z'; i++) {
    if (max < c[i] + c[i -32]) {
      max = c[i] + c[i-32];
      a = i;
    }
  }
  cout << a << " "  << max;
  return 0;
}
