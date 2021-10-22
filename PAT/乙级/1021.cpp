#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s;
  vector<int> v(10);
  // int v[10] = {0};
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    v[s[i] - '0']++;
  }
  for (int i = 0; i < v.size(); i++) {
    if(v[i] > 0) {
      printf("%d:%d\n",i,v[i]);
    }
  }
}
