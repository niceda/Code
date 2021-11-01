#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, tmp, ys;
  vector<int> a(5);
  float a3m, a3 = 0;
  int flag = 1;
  vector<int> v(5);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    ys = tmp % 5;
    if (ys == 0 && tmp % 2 == 0) {
      a[0] += tmp;
      v[0] = 1;
    } else if (ys == 1) {
      a[1] += flag * tmp;
      flag = -flag;
      v[1] = 1;
    } else if (ys == 2) {
      a[2]++;
      v[2] = 1;
    } else if (ys == 3) {
      a3 += tmp;
      a[3]++;
      v[3] = 1;
    } else if (ys == 4) {
      if (tmp > a[4])
        a[4] = tmp;
      v[4] = 1;
    }
  }
  if (v[3])
    a3m = a3 / a[3];
  for (int i = 0; i < v.size(); i++) {
    if (i != 0)
      cout << " ";
    if (v[i] == 0)
      cout << "N";
    else if (i == 3)
      printf("%.1f", a3m);
    else
      cout << a[i];
  }
}
