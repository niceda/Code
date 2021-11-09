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
      string temp = num.substr(num.length() - s1.length());
      if (temp == s1) {
        printf("%d %s\n", j, num.c_str());
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      printf("No\n");
  }
  return 0;
}
