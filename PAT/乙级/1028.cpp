#include <iostream>
#include <vector>
using namespace std;

struct node {
  string name;
  string riqi;
};

int main() {
  int n, flag = 0;
  cin >> n;
  int a = n;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].name >> v[i].riqi;
  }
  string minname, minriqi, maxname, maxriqi;
  for (int i = 0; i < n; i++) {
    if (v[i].riqi.compare("1814/09/06") < 0 ||
        v[i].riqi.compare("2014/09/06") > 0) {
      a--;
      continue;
    }
    if (flag == 0) {
      minname = v[i].name, minriqi = v[i].riqi, maxname = v[i].name,
      maxriqi = v[i].riqi;
      flag = 1;
    }
    if (v[i].riqi.compare(maxriqi) > 0) {
      maxriqi = v[i].riqi;
      maxname = v[i].name;
    }
    if (v[i].riqi.compare(minriqi) < 0) {
      minriqi = v[i].riqi;
      minname = v[i].name;
    }
  }
  if (flag == 1)
    cout << a << " " << minname << " " << maxname;
  else
    cout << a;
  return 0;
}
