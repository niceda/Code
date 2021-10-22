#include <iostream>
using namespace std;

int main() {
  int v[10];
  string s;
  for (int i = 0; i < 10; i++) {
    cin >> v[i];
  }
  for (int i = 1; i < 10; i++) {
    if (v[i] != 0) {
      s.push_back(i+'0');
      v[i]--;
      break;
    }
  }
  for (int i = 0; i < 10; i++) {
    while (v[i] != 0) {
      s.push_back(i+'0');
      v[i]--;
    }
  }
  cout << s;
}
