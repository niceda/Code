#include <iostream>
#include <set>
using namespace std;

int main() {
  int N, t, flag = 0;
  cin >> N;
  set<int> s;
  for (int i = 0; i < N; i++) {
    int temp = 0;
    cin >> t;
    while (t != 0) {
      temp += t % 10;
      t = t / 10;
    }
    s.insert(temp);
  }
  cout << s.size() << endl;
  for (auto u : s) {
    if (flag != 0)
      cout << " ";
    cout << u;
    flag = 1;
  }
  return 0;
}
