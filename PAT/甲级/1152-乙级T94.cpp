#include <iostream>
#include <ostream>
using namespace std;

bool isprimer(int num) {
  if (num == 1 || num == 0)
    return false;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

int main() {
  int l, k;
  string s;
  cin >> l >> k >> s;
  for (int i = 0; i < s.length() - k + 1; i++) {
    string sub = s.substr(i, k);
    int temp = std::stoi(sub);
    if (isprimer(temp)) {
      cout << sub;
      return 0;
    }
  }
  cout << "404";
  return 0;
}
