#include <iostream>
#include <map>
using namespace std;

int main() {
  map<int, float> result;
  int k, e, count = 0;
  float c;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> e;
    cin >> result[e];
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> e >> c;
    result[e] += c;
  }

  for (auto i = result.begin(); i != result.end();) {
    if ((*i).second == 0) {
      i = result.erase(i);
    } else {
      count++;
      i++;
    }
  }

  cout << count;
  for (auto i = result.rbegin(); i != result.rend(); i++) {
    printf(" %d %.1f", i->first, i->second);
  }
  return 0;
}
