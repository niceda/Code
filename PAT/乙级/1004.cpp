#include <iostream>
using namespace std;

int main() {
  int n, maxgrade = -1, mingrade = 101, score;
  cin >> n;
  string maxname, maxnum, minname, minnum, name, num;
  for (int i = 0; i < n; i++) {
    cin >> name >> num >> score;
    if (score > maxgrade) {
      maxname = name;
      maxnum = num;
      maxgrade = score;
    }
    if (score < mingrade) {
      minname = name;
      minnum = num;
      mingrade = score;
    }
  }
  cout << maxname << " " << maxnum << endl << minname << " " << minnum;
}
