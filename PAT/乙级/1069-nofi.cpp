#include <iostream>
#include <set>
using namespace std;

int main() {
  int M, N, S, n = 1, next = 0;
  cin >> M >> N >> S;
  set<string> set;
  string t;
  if (M < S) {
    cout << "Keep going...";
  } else {
    while (M--) {
      cin >> t;
      if ((n - S - next) % N == 0) {
        if (set.find(t) == set.end()) {
          set.insert(t);
          cout << t << endl;
        } else
          next++;
      }
      n++;
    }
  }
  return 0;
}
