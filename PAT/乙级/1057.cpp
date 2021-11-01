#include <iostream>
#include <cctype>
using namespace std;

int main() {
  string s;
  getline(cin, s);
  int N = 0, ling = 0, yi = 0;
  for (int i = 0; i < s.length(); i++) {
    if (isalpha(s[i]))
      N += toupper(s[i]) - 64;
  }
  while(N) {
    if ( N % 2 == 1)
      yi++;
    else
     ling++;
    N = N / 2;
  }
  cout << ling << " " << yi;
  return 0;
}
