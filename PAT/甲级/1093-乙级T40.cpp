#include <iostream>
using namespace std;

int main() {
  long long result = 0;
  int t = 0, p = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if( s[i] == 'T') {
      t++;
    }
  }
  for (int i = 0, j = t; i < s.length() && t > 0; i++) {
    if (s[i] == 'A') 
      result += p * t;
    if (s[i] == 'P') 
      p++;
    if (s[i] == 'T')
      t--;
  }
  result %= 1000000007;
  cout << result;
  return 0;
}
