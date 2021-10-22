#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool isprime(int num) {
    for (int j = 2; j <= sqrt(num); j++) {
      if (num % j == 0)
        return false;
    }
    return true;
  }

int main() {
  int k, n = 0, j;
  cin >> k;
  vector<int> s;
  for (int i = 3; i < k + 1;) {
    if(isprime(i))
      s.push_back(i);
    i += 2;
  }
  if (s.empty()) {
    cout << 0;
    return 0;
  }
  for (auto it = s.begin(); it != s.end() - 1; it++) {
    if (*(it + 1) - *it == 2)
      n++;
  }
  cout << n;
  return 0;
}
