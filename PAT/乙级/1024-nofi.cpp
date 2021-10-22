#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  string sub1 = s.substr(1, s.find('E') - 1), sub2 = s.substr(s.find('E') + 1);
  sub1.erase(1, 1);
  if (sub2[0] == '+') {
    sub2.erase(0, 1);
    int i = std::stoi(sub2);
    if(i >= sub1.length() - 1) {
      sub1.append(i - sub1.length() - 1, '0');
    }
    else
      sub1.insert(i+1,1,'.');

  }
  if (sub2[0] == '-') {
    sub2.erase(0,1);
    int i = std::stoi(sub2);
    sub1.insert(0,i,'0');
    sub1.insert(1,1,'.');
  }
  if(s[0] == '-') cout << s[0];
  cout << sub1;
  return 0;
}
