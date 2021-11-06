#include <iostream>
#include <set>
using namespace std;

int main() {
  int M, N, S, n = 1, nxt = 0;
  cin >> M >> N >> S;
  set<string> sset;
  string s;
  if (M < S) {
    cout << "Keep going...";
  } else {
    while (M--) {
      cin >> s;
      if ((n - S - nxt) % N == 0) {
        if (sset.find(s) == sset.end()) {
          sset.insert(s);
          cout << s << endl;
        } else
          nxt++;
      }
      n++;
    }
  }
  return 0;
}
