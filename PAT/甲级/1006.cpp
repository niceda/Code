#include <iostream>
using namespace std;

int main() {
  string stid, edid, tempid, st = "25", ed = "-1", tempst, temped;
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> tempid >> tempst >> temped;
    if (tempst < st) {
      stid = tempid;
      st = tempst;
    }
    if (temped > ed) {
      edid = tempid;
      ed = temped;
    }
  }
  cout << stid << " " << edid;
  return 0;
}
