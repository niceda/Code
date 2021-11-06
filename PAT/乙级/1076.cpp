#include <iostream>
#include <map>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<char, int> m = {{'A', 1}, {'B', 2}, {'C', 3}, {'D', 4} };
  for (int i = 0; i < 4 * N; i++) {
    char t1, t2;
    scanf(" %c-%c", &t1, &t2);
    if (t2 == 'T')
      cout << m[t1];
  }
  return 0;
}
