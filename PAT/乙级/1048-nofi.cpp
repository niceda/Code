#include <iostream>
using namespace std;

int main() {
  string A, B, s;
  cin >> A >> B;
  int flag = 1, length = A.length() > B.length() ? B.length() : A.length();
  int j = B.length() - 1;
  for (int i = A.length() - 1, tmp = A.length() - length; i >= tmp; i--, j--) {
    if (flag == 1) {
      int r = (B[j] - '0' + A[i] - '0') % 13;
      if (r == 10)
        s.insert(0, 1, 'J');
      else if (r == 11)
        s.insert(0, 1, 'Q');
      else if (r == 12)
        s.insert(0, 1, 'K');
      else
        s.insert(0, 1, r + '0');
      flag = -flag;
      continue;
    }
    if (flag == -1) {
      int r = B[j] - A[i];
      if (r < 0)
        r = r + 10;
      s.insert(0, 1, r + '0');
      flag = -flag;
    }
  }
  while (j >= 0) {
    s.insert(0, 1, B[j]);
    j--;
  }
  cout << s;
  return 0;
}
