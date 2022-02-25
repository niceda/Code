#include <iostream>
#include <map>
using namespace std;

bool isprime(int a) {
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0)
      return false;
  }
  return true;
}

int main() {
  int N, k;
  cin >> N;
  map<string, int> m;
  for (int i = 1; i <= N; i++) {
    string s;
    cin >> s;
    m[s] = i;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    string s;
    cin >> s;
    if (m.find(s) != m.end()) {
      if (m[s] == -1)
        cout << s << ": Checked" << endl;
      else if (m[s] == 1)
        cout << s << ": Mystery Award" << endl;
      else if (isprime(m[s]))
        cout << s << ": Minion" << endl;
      else
        cout << s << ": Chocolate" << endl;
      m[s] = -1;
    } else
      cout << s << ": "
           << "Are you kidding?" << endl;
  }
}

