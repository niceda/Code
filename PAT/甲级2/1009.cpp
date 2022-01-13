#include<iostream>
#include<map>
using namespace std;

int main() {
  int k;
  cin >> k;
  map<int, float> a;
  map<int, float> b;
  map<int, float> result;
  int e;
  float c;
  for (int i = 0; i < k; i++) {
    cin >> e >> c;
    a[e] = c;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> e >> c;
    b[e] = c;
  }
  for (auto ita = a.begin(); ita != a.end(); ita++) {
    for (auto itb = b.begin(); itb != b.end(); itb++) {
      result[ita->first + itb->first] += ita->second * itb->second;
    }
  }

  int count = 0;
  for (auto it = result.begin(); it != result.end(); it++) {
    if (it->second != 0) {
      count++;
    }
  }
  cout << count;
  for (auto it = result.rbegin(); it != result.rend(); it++) {
    if (it->second != 0) {
      printf(" %d %.1f", it->first, it->second);
    }
  }
  return 0;
}
