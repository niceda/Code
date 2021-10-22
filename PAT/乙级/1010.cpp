#include <iostream>
using namespace std;

int main() {
  int xishu, zhishu, first = 0,flag = 0;
  while (cin >> xishu >> zhishu) {
    if (zhishu == 0 && first == 0) {
      cout << 0 << " " << 0;
      return 0;
    }
    first = 1;
    if (zhishu == 0) {
      break;
    }
    if (flag == 1) cout << " ";
    cout << xishu * zhishu << " " << zhishu - 1;
    flag = 1;
  }
}
