#include <iostream>
#include <string>
using namespace std;

int main() {
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int t, N = -1, flag = 0;
    string num;
    cin >> t;
    for (int j = 1; j < 10; j++) {
      num = to_string(t * t * j);
      string s1 = to_string(t);
      string temp(num.length() - s1.length(), '0');
      s1 = temp + s1;
      for (int l = s1.length() - 1; l >= temp.length(); l--) {
        if (num[l] != s1[l])
          flag = 1;
      }
      if (flag == 0) {
        N = j;
        break;
      } else
        flag = 0;
    }
    if (N == -1)
      cout << "No" << endl;
    else
      cout << N << " " << num << endl;
  }
  return 0;
}
