#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int v[10] = {0};
  for (int i = 0; i < s.length(); i++) {
    v[s[i] - '0']++;
  }
  for (int i = 0; i < 10; i++) {
    if(v[i] > 0) {
      printf("%d:%d\n",i,v[i]);
    }
  }
}
