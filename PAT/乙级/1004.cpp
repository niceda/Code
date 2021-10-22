#include <iostream>
using namespace std;

int main() {
  int n, maxgrade, mingrade;
  cin >> n;
  string maxname, maxnum, minname, minnum;
  cin >> maxname >> maxnum >> maxgrade;
  minname = maxname;
  minnum = maxnum;
  mingrade = maxgrade;
  for (int i = 0; i < n - 1; i++) {
    int tmpgrade;
    string tmpname, tmpnum;
    cin >> tmpname >> tmpnum >> tmpgrade;
    if (tmpgrade > maxgrade) {
      maxname = tmpname;
      maxnum = tmpnum;
      maxgrade = tmpgrade;
    }
    if (tmpgrade < mingrade) {
      minname = tmpname;
      minnum = tmpnum;
      mingrade = tmpgrade;
    }
  }
  cout << maxname << " " << maxnum << endl << minname << " " << minnum;
}
