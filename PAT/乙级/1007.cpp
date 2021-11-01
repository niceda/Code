#include <iostream>
using namespace std;

bool isprime(int num) {
    for (int i = 2; i * i  <= num; i++) {
      if (num % i == 0)
        return false;
    }
    return true;
  }

int main() {
  int N, cnt = 0;
  cin >> N;
  for (int i = 3; i < N - 1; i++) {
    if(isprime(i) && isprime(i+2))
      cnt++;
  }
  cout << cnt;
  return 0;
}
