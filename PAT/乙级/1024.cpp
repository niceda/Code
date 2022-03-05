#include <iostream>
using namespace std;

int main() {
  char c = getchar(), t;
  string s;
  while ((t = cin.get()) != 'E')
    s += t;
  s.erase(1, 1);
  int e;
  cin >> e;
  if (e >= 0) {
    if(s.length() - 1 > e)
      s.insert(1 + e, 1, '.');
    else {
      string temp(e - s.length() + 1, '0');
      s += temp;
    }
  } else {
    string temp1 = "0.";
    string temp2(abs(e) - 1, '0');
    s = temp1 + temp2 + s;
  }
  if (c == '-')
    cout << c;
  cout << s;
  return 0;
}
