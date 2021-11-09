#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, a = 0, b = 0, c = 0;
  cin >> n;
  map<char, int> m1;
  map<char, int> m2;
  for (int i = 0; i < n; i++) {
    char t1, t2;
    cin >> t1 >> t2;
    if (t1 == t2) {
      b++;
    } else if ((t1 == 'C' && t2 == 'J') || (t1 == 'J' && t2 == 'B') ||
               (t1 == 'B' && t2 == 'C')) {
      a++;
      m1[t1]++;
    } else {
      c++;
      m2[t2]++;
    }
  }
  printf("%d %d %d\n", a, b, c);
  printf("%d %d %d\n", c, b, a);
  char maxjia = m1['C'] > m1['B'] ? 'C' : 'B';
  maxjia = m1['J'] > m1[maxjia] ? 'J' : maxjia;
  char maxyi = m2['C'] > m2['B'] ? 'C' : 'B';
  maxyi = m2['J'] > m2[maxyi] ? 'J' : maxyi;
  cout << maxjia << " " << maxyi;
}
