#include <iostream>
using namespace std;

int main() {
  long a, b, c, cnt = 1;
  cin >> a >> b;
  c = a + b;
  if (c < 0) {
    cout << "-";
    c = -c;
  }
  string s = to_string(c);
  string ans;
  for (int i = s.length() - 1; i >= 0; i--) {
    if ((cnt - 1) % 3 == 0 && cnt != 1)
      ans.insert(0, 1, ',');
    ans.insert(0, 1, s[i]);
    cnt++;
  }
  cout << ans;
  return 0;
}
